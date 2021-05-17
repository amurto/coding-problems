// https://codeforces.com/contest/1344/problem/B
// Monopole Magnets

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

void dfs(vector<string> &grid, vector<vector<bool>> &vis, int i, int j, int n, int m)
{
    vis[i][j] = true;
    for (int dir = 0; dir < 4; dir++)
    {
        int ni = i + di[dir], nj = j + dj[dir];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '#' && !vis[ni][nj])
            dfs(grid, vis, ni, nj, n, m);
    }
}

int solve()
{
    int n, m, r = 0, c = 0;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>> vis(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    for (int i = 0; i < n; i++)
    {
        int con = 0, b = 0;
        char last = '.';
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#')
                con += (last == '.');
            last = grid[i][j];
        }
        if (con > 1)
            return -1;
        if (con == 0)
            r = 1;
    }
    for (int j = 0; j < m; j++)
    {
        int con = 0, b = 0;
        char last = '.';
        for (int i = 0; i < n; i++)
        {
            if (grid[i][j] == '#')
                con += (last == '.');
            last = grid[i][j];
        }
        if (con > 1)
            return -1;
        if (con == 0)
            c = 1;
    }
    if ((r + c) & 1)
        return -1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#' && !vis[i][j])
            {
                dfs(grid, vis, i, j, n, m);
                res++;
            }
        }
    }
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