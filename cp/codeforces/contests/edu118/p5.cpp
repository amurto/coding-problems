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

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<vector<int>> w(n, vector<int>(m)), deg(n, vector<int>(m)), vis(n, vector<int>(m));
    int li = 0, lj = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'L')
                li = i, lj = j;
            for (int dir = 0; dir < 4; dir++)
            {
                int ni = i + di[dir], nj = j + dj[dir];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && (grid[ni][nj] == 'L' || grid[ni][nj] == '.'))
                    deg[i][j]++;
            }
        }
    }
    w[li][lj] = 1;
    queue<pii> q;
    for (int dir = 0; dir < 4; dir++)
    {
        int ni = li + di[dir], nj = lj + dj[dir];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '.')
        {
            deg[ni][nj]--;
            if (deg[ni][nj] < 2)
            {
                q.push({ni, nj});
                vis[ni][nj] = 1;
            }
        }
    }
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        int cnt = 0, cntW = 0;
        for (int dir = 0; dir < 4; dir++)
        {
            int ni = cur.first + di[dir], nj = cur.second + dj[dir];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && (grid[ni][nj] == 'L' || grid[ni][nj] == '.'))
            {
                cnt++;
                cntW += w[ni][nj];
            }
        }
        if (cntW >= cnt - 1)
            w[cur.first][cur.second] = 1;
        for (int dir = 0; dir < 4; dir++)
        {
            int ni = cur.first + di[dir], nj = cur.second + dj[dir];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '.' && !vis[ni][nj])
            {
                deg[ni][nj]--;
                if (deg[ni][nj] < 2)
                {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] != 'L' && w[i][j])
                grid[i][j] = '+';
    for (string s : grid)
        cout << s << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}