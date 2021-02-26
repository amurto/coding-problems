// https://codeforces.com/contest/811/problem/D
// Vladik and Favorite Game

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 105, inf = 1e6 + 5;
string grid[N];
int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

void query(char ch, int &x, int &y)
{
    cout << ch << "\n";
    fflush(stdout);
    cin >> x >> y;
    x--;
    y--;
    if ((x == -2 && y == -2) || grid[x][y] == 'F')
        exit(0);
}

bool valid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '*';
}

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
        if (valid(pi, pj, n, m) && !vis[pi][pj])
        {
            int res = 1 + dfs(nxt, dis, vis, pi, pj, n, m, (d + 2) % 4);
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
    query(dir[nxt[ci][cj]], x, y);
    if (x == -2 && y == -2)
        return;
    trace(dir, nxt, x, y);
}

void fixDU(vector<char> &dir, int ci, int cj, int n, int m, bool &fDU)
{
    int x, y;
    if (valid(ci + di[1], cj + dj[1], n, m))
    {
        query('D', x, y);
        fDU = true;
        if (x == ci + di[1] && y == cj + dj[1])
            query('U', x, y);
        else
            swap(dir[1], dir[3]);
    }
    if (!fDU && valid(ci + di[0], cj + dj[0], n, m))
    {
        query(dir[0], x, y);
        fixDU(dir, x, y, n, m, fDU);
        query(dir[2], x, y);
    }
}

void fixRL(vector<char> &dir, int ci, int cj, int n, int m, bool &fRL)
{
    int x, y;
    if (valid(ci + di[0], cj + dj[0], n, m))
    {
        query('R', x, y);
        fRL = true;
        if (x == ci + di[0] && y == cj + dj[0])
            query('L', x, y);
        else
            swap(dir[0], dir[2]);
    }
    if (!fRL && valid(ci + di[1], cj + dj[1], n, m))
    {
        query(dir[1], x, y);
        fixRL(dir, x, y, n, m, fRL);
        query(dir[3], x, y);
    }
}

void solve()
{
    int n, m, x, y, ci = 0, cj = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    if (n + m == 2)
        return;
    vector<char> dir = {'R', 'D', 'L', 'U'};
    vector<vector<int>> nxt(n, vector<int>(m, -1)), dis(n, vector<int>(m, inf));
    vector<vector<bool>> vis(n, vector<bool>(m));
    dfs(nxt, dis, vis, 0, 0, n, m, 0);
    if (n == 1)
    {
        query('R', x, y);
        if (x == 0 && y == 0)
            swap(dir[0], dir[2]);
        else
            query('L', x, y);
        trace(dir, nxt, 0, 0);
        return;
    }
    if (m == 1)
    {
        query('D', x, y);
        if (x == 0 && y == 0)
            swap(dir[1], dir[3]);
        else
            query('U', x, y);
        trace(dir, nxt, 0, 0);
        return;
    }
    bool fRL = false, fDU = false;
    if (grid[0][1] != '*')
    {
        query('R', x, y);
        fRL = true;
        if (x == 0 && y == 0)
            swap(dir[0], dir[2]);
        else
            query('L', x, y);
        fixDU(dir, x, y, n, m, fDU);
    }
    if (!fDU && grid[1][0] != '*')
    {
        query('D', x, y);
        fDU = true;
        if (x == 0 && y == 0)
            swap(dir[1], dir[3]);
        else
            query('U', x, y);
        fixRL(dir, x, y, n, m, fRL);
    }
    trace(dir, nxt, 0, 0);
}

int main()
{
    solve();
    return 0;
}