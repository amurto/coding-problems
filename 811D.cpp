// https://codeforces.com/contest/811/problem/D
// Vladik and Favorite Game

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 105, inf = 1e6 + 5;
string grid[N];
int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

int dfs(vector<vector<int>> &nxt, vector<vector<int>> &dis, vector<vector<bool>> &vis, int ci, int cj, int n, int m, int b)
{
    if (grid[ci][cj] == 'F')
    {
        nxt[ci][cj] = 4;
        return 1;
    }
    nxt[ci][cj] = b;
    vis[ci][cj] = true;
    for (int d = 0; d < 4; d++)
    {
        int pi = ci + di[d], pj = cj + dj[d];
        if (pi >= 0 && pi < n && pj >= 0 && pj < m && !vis[pi][pj] && grid[pi][pj] != '*')
        {
            int res = dfs(nxt, dis, vis, pi, pj, n, m, d);
            if (res < dis[ci][cj])
            {
                dis[ci][cj] = res;
                nxt[ci][cj] = d;
            }
        }
    }
    return dis[ci][cj];
}

void trace(vector<char> &dir, vector<vector<int>> &nxt, int ci, int cj)
{
    if (grid[ci][cj] == 'F')
        return;
    int x, y;
    cout << dir[nxt[ci][cj]] << "\n";
    fflush(stdout);
    cin >> x >> y;
    if (x == -1 && y == -1)
        return;
    trace(dir, nxt, --x, --y);
}

void fix(int ci, int cj)
{
}

void solve()
{
    int n, m, ci = 0, cj = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<char> dir = {'R', 'D', 'L', 'U'};
    vector<vector<int>> nxt(n, vector<int>(m, -1)), dis(n, vector<int>(m, inf));
    vector<vector<bool>> vis(n, vector<bool>(m));
    dfs(nxt, dis, vis, 0, 0, n, m, 0);
    trace(dir, nxt, ci, cj);
}

int main()
{
    solve();
    return 0;
}