// https://codeforces.com/contest/378/problem/C
// Maze

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

void dfs(vector<vector<char>> &maze, vector<vector<bool>> &vis, int &k, int i, int j, int n, int m)
{
    if (k == 0)
        return;
    vis[i][j] = true;
    for (int dir = 0; dir < 4; dir++)
    {
        int r = i + di[dir], c = j + dj[dir];
        if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && maze[r][c] == '.')
            dfs(maze, vis, k, r, c, n, m);
        if (k == 0)
            return;
    }
    maze[i][j] = 'X';
    k--;
}

void display(vector<vector<char>> &maze, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << maze[i][j];
        cout << "\n";
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> maze(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    pair<int, int> start = {-1, -1};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];

    if (k == 0)
    {
        display(maze, n, m);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == '.')
            {
                dfs(maze, vis, k, i, j, n, m);
                break;
            }
        }
    }
    display(maze, n, m);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}