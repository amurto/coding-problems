#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int dp[501][501];

ll dfs(vector<vector<char>> &grid, int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '.')
        return 0;
    if (dp[i][j] == 0)
    {
        ll c1 = dfs(grid, i + 1, j - 1, n, m);
        ll c2 = dfs(grid, i + 1, j, n, m);
        ll c3 = dfs(grid, i + 1, j + 1, n, m);
        dp[i][j] = 1 + min({c1, c2, c3});
    }
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        memset(dp, 0, sizeof(dp));
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '.' || dp[i][j] > 0)
                    continue;
                dfs(grid, i, j, n, m);
            }
        }
        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++) 
                sum += dp[i][j];
        cout << sum << "\n";
    }
    return 0;
}