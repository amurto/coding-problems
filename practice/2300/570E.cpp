// https://codeforces.com/contest/570/problem/E
// Pig and Palindromes

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MOD = 1e9 + 7, N = 505;
vector<pii> st[2 * N];
int dis[N][N], pos[N][N];
bool vis[N][N];

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

void dfs(vector<string> &grid, int i, int j, int n, int m, int val)
{
    vis[i][j] = true;
    dis[i][j] = val;
    st[dis[i][j]].pb({i, j});
    pos[i][j] = (int)st[dis[i][j]].size() - 1;
    if (i + 1 < n && !vis[i + 1][j])
        dfs(grid, i + 1, j, n, m, dis[i][j] + 1);
    if (j + 1 < m && !vis[i][j + 1])
        dfs(grid, i, j + 1, n, m, dis[i][j] + 1);
}

int solve()
{
    int n, m, res = 0;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vis[i][j] = false;
    dfs(grid, 0, 0, n, m, 0);
    int moves = n + m - 1;
    int mx = (moves + 1) / 2;
    vector<vector<vector<int>>> dp(mx);
    for (int i = 0, j = moves - 1; i < mx; i++, j--)
    {
        int sz1 = (int)st[i].size(), sz2 = (int)st[j].size();
        dp[i].resize(sz1);
        for (int k = 0; k < sz1; k++)
            dp[i][k].resize(sz2);
    }
    if (moves & 1)
        for (int i = 0; i < (int)dp[mx - 1].size(); i++)
            dp[mx - 1][i][i] = 1;
    else
    {
        for (pii p : st[mx - 1])
        {
            if (p.first + 1 < n && grid[p.first][p.second] == grid[p.first + 1][p.second])
                dp[mx - 1][pos[p.first][p.second]][pos[p.first + 1][p.second]] = 1;
            if (p.second + 1 < m && grid[p.first][p.second] == grid[p.first][p.second + 1])
                dp[mx - 1][pos[p.first][p.second]][pos[p.first][p.second + 1]] = 1;
        }
    }
    for (int i = mx - 2; i >= 0; i--)
    {
        int v = moves - i - 1;
        for (pii p1 : st[i])
        {
            int x = pos[p1.first][p1.second];
            for (pii p2 : st[v])
            {
                if (grid[p1.first][p1.second] == grid[p2.first][p2.second])
                {
                    int y = pos[p2.first][p2.second];
                    int i1 = p1.first + 1, j1 = p1.second;
                    if (i1 < n)
                    {
                        int i2 = p2.first - 1, j2 = p2.second;
                        if (i2 >= 0)
                            dp[i][x][y] = add(dp[i][x][y], dp[i + 1][pos[i1][j1]][pos[i2][j2]]);
                        i2++;
                        j2--;
                        if (j2 >= 0)
                            dp[i][x][y] = add(dp[i][x][y], dp[i + 1][pos[i1][j1]][pos[i2][j2]]);
                    }
                    i1--;
                    j1++;
                    if (j1 < m)
                    {
                        int i2 = p2.first - 1, j2 = p2.second;
                        if (i2 >= 0)
                            dp[i][x][y] = add(dp[i][x][y], dp[i + 1][pos[i1][j1]][pos[i2][j2]]);
                        i2++;
                        j2--;
                        if (j2 >= 0)
                            dp[i][x][y] = add(dp[i][x][y], dp[i + 1][pos[i1][j1]][pos[i2][j2]]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < (int)dp[0].size(); i++)
        for (int j = 0; j < (int)dp[0][i].size(); j++)
            res = add(res, dp[0][i][j]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}