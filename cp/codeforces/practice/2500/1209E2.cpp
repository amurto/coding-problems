// https://codeforces.com/contest/1209/problem/E2
// Rotate Columns (hard version)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 13, M = 2005, ninf = -1e9;
int grid[N][M];

void rotate(int &mask, int n)
{
    int last = (mask & 1);
    mask >>= 1;
    mask |= (last << (n - 1));
}

int dfs(vector<vector<int>> &dp, vector<vector<int>> &sum, vector<int> &cols, int cur, int mask, int n, int m)
{
    if (mask == ((1 << n) - 1))
        return 0;
    if (cur == min(n, m))
        return -1e8;
    if (dp[cur][mask] <= ninf)
    {
        int res = -1e8;
        for (int i = 0; i < (1 << n); i++)
        {
            int j = i;
            for (int k = 0; k < n; k++, rotate(j, n))
                if ((mask & j) == 0)
                    res = max(res, sum[cur][i] + dfs(dp, sum, cols, cur + 1, mask | j, n, m));
        }
        dp[cur][mask] = res;
    }
    return dp[cur][mask];
}

int solve()
{
    int n, m;
    cin >> n >> m;
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
    vector<vector<int>> dp(n, vector<int>(1 << n, ninf)), sum(m, vector<int>(1 << n));
    for (int i = 0; i < m; i++)
        for (int mask = 0; mask < (1 << n); mask++)
            for (int j = 0; j < n; j++)
                if ((mask >> j) & 1)
                    sum[i][mask] += grid[j][cols[i]];
    return dfs(dp, sum, cols, 0, 0, n, m);
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