#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m)), mx_row(n, vector<int>(k, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    for (int i = 0; i < n; i++)
    {
        int h = m / 2;
        vector<vector<int>> prev(h + 1, vector<int>(k, -1));
        prev[0][0] = 0;
        for (int j = 0; j < m; j++)
        {
            vector<vector<int>> cur = prev;
            for (int t = 1; t <= min(h, j + 1); t++)
                for (int e = 0; e < k; e++)
                    if (prev[t - 1][e] >= 0)
                        cur[t][(e + grid[i][j]) % k] = max(cur[t][(e + grid[i][j]) % k], grid[i][j] + prev[t - 1][e]);
            prev = cur;
        }
        for (int j = 0; j < k; j++)
            for (int t = 1; t <= h; t++)
                mx_row[i][j] = max(mx_row[i][j], prev[t][j]);
    }
    vector<int> dp(k, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> tdp = dp;
        for (int p = 0; p < k; p++)
            for (int j = 0; j < k; j++)
                if (dp[p] >= 0 && mx_row[i][j] >= 0)
                    tdp[(p + j) % k] = max(tdp[(p + j) % k], mx_row[i][j] + dp[p]);
        dp = tdp;
    }
    return dp[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}