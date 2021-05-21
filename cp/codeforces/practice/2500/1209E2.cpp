// https://codeforces.com/contest/1209/problem/E2
// Rotate Columns (hard version)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int rotate(int mask, int n)
{
    int last = (mask & 1);
    mask >>= 1;
    mask |= (last << (n - 1));
    return mask;
}

int solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<int> cols(m), cmx(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            cmx[j] = max(cmx[j], grid[i][j]);
        }
    }
    iota(cols.begin(), cols.end(), 0);
    sort(cols.begin(), cols.end(), [&](int &i1, int &i2)
         { return cmx[i1] > cmx[i2]; });
    vector<vector<int>> dp(n, vector<int>(1 << n)), sum(m, vector<int>(1 << n));
    for (int i = 0; i < min(n, m); i++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {
            int val = 0, rmask = mask;
            for (int j = 0; j < n; j++)
                if ((mask >> j) & 1)
                    val += grid[j][cols[i]];
            for (int r = 0; r < n; r++, rmask = rotate(rmask, n))
                sum[i][rmask] = max(sum[i][rmask], val);
        }
    }
    for (int mask = 0; mask < (1 << n); mask++)
        dp[0][mask] = sum[0][mask];
    for (int i = 1; i < min(n, m); i++)
        for (int mask = 0; mask < (1 << n); mask++)
            for (int j = mask; j < (1 << n); j = (j + 1) | mask)
                dp[i][j] = max(dp[i][j], sum[i][j ^ mask] + dp[i - 1][mask]);
    return dp[min(n, m) - 1][(1 << n) - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}