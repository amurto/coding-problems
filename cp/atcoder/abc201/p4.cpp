#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 2e4;
int dfs(vector<string> &grid, vector<vector<int>> &dp, int i, int j, int n, int m)
{
    if (i == n - 1 && j == m - 1)
    {
        if (i + j == 0)
            return 0;
        int dis = (i + j) % 2;
        if (dis == 0)
            return grid[i][j] == '+' ? -1 : 1;
        return grid[i][j] == '+' ? 1 : -1;
    }
    if (dp[i][j] <= -inf)
    {
        int res = 0, c = 0, dis = (i + j) % 2;
        if (dis == 0)
        {
            res = -inf;
            if (i + j > 0)
            {
                if (grid[i][j] == '+')
                    c--;
                else
                    c++;
            }
            if (i + 1 < n)
                res = max(res, c + dfs(grid, dp, i + 1, j, n, m));
            if (j + 1 < m)
                res = max(res, c + dfs(grid, dp, i, j + 1, n, m));
        }
        else
        {
            res = inf;
            if (i + j > 0)
            {
                if (grid[i][j] == '+')
                    c++;
                else
                    c--;
            }
            if (i + 1 < n)
                res = min(res, c + dfs(grid, dp, i + 1, j, n, m));
            if (j + 1 < m)
                res = min(res, c + dfs(grid, dp, i, j + 1, n, m));
        }
        dp[i][j] = res;
    }
    return dp[i][j];
}

string solve()
{
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    vector<vector<int>> dp(h, vector<int>(w, -inf));
    for (int i = 0; i < h; i++)
        cin >> grid[i];
    int p = dfs(grid, dp, 0, 0, h, w);
    if (p > 0)
        return "Takahashi";
    else if (p == 0)
        return "Draw";
    return "Aoki";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}