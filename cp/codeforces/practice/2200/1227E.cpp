// https://codeforces.com/contest/1227/problem/E
// Arson In Berland Forest

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

// king moves
int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void display(vector<string> &grid, int n)
{
    for (string s : grid)
        cout << s << "\n";
}

bool pos(vector<string> &grid, vector<vector<int>> &vis, int n, int m, int steps)
{
    vector<string> tmp(n, string(m, '.'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (vis[i][j] >= steps)
                tmp[i][j] = 'X';
    queue<pii> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tmp[i][j] == 'X')
            {
                int cnt = 0;
                for (int dir = 0; dir < 8; dir++)
                {
                    int ni = i + di[dir], nj = j + dj[dir];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && tmp[ni][nj] == 'X')
                        cnt++;
                }
                if (cnt < 8)
                    q.push({i, j});
            }
        }
    }
    while (steps > 0 && !q.empty())
    {
        int sz = q.size();
        while (sz > 0)
        {
            pii cur = q.front();
            q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int ni = cur.first + di[dir], nj = cur.second + dj[dir];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && tmp[ni][nj] == '.')
                {
                    q.push({ni, nj});
                    tmp[ni][nj] = 'X';
                }
            }
            sz--;
        }
        steps--;
    }
    for (int i = 0; i < n; i++)
        if (grid[i] != tmp[i])
            return false;
    return true;
}

void solve()
{
    int n, m, mx = 0;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<int>> cells(n, vector<int>(m)), vis(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    queue<pii> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'X')
            {
                int cnt = 0;
                for (int dir = 0; dir < 8; dir++)
                {
                    int ni = i + di[dir], nj = j + dj[dir];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 'X')
                        cnt++;
                }
                if (cnt < 8)
                {
                    q.push({i, j});
                    vis[i][j] = 0;
                }
            }
        }
    }
    while (!q.empty())
    {
        int sz = q.size();
        while (sz > 0)
        {
            pii cur = q.front();
            q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int ni = cur.first + di[dir], nj = cur.second + dj[dir];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && vis[ni][nj] == -1 && grid[ni][nj] == 'X')
                {
                    q.push({ni, nj});
                    vis[ni][nj] = vis[cur.first][cur.second] + 1;
                    mx = max(mx, vis[ni][nj]);
                }
            }
            sz--;
        }
    }
    int low = 0, high = mx, res = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (pos(grid, vis, n, m, mid))
        {
            low = mid + 1;
            res = max(res, mid);
        }
        else
            high = mid - 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (vis[i][j] >= res)
                grid[i][j] = 'X';
            else
                grid[i][j] = '.';
    cout << res << "\n";
    display(grid, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}