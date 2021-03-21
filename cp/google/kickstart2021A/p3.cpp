#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void display(vector<vector<int>> &grid, int r, int c)
{
    cout << "\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

ll bfs(vector<vector<int>> &grid, int r, int c, int mx)
{
    ll res = 0;
    int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
    vector<vector<bool>> vis(r, vector<bool>(c));
    queue<pii> q;
    map<int, vector<pii>> mp;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mp[grid[i][j]].pb({i, j});
            if (grid[i][j] == mx)
            {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }
    int cur = mx - 1;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            pii tp = q.front();
            int i = tp.first, j = tp.second;
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int ni = i + di[dir], nj = j + dj[dir];
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && !vis[ni][nj])
                {
                    int req = grid[i][j] - 1;
                    res += abs(grid[ni][nj] - req);
                    grid[ni][nj] = req;
                    vis[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
        for (pii p : mp[cur])
        {
            if (!vis[p.first][p.second])
            {
                q.push({p.first, p.second});
                vis[p.first][p.second] = true;
            }
        }
        cur--;
    }
    return res;
}
ll solve()
{
    int r, c, mx = 0;
    ll res = 0;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            mx = max(mx, grid[i][j]);
        }
    }
    return bfs(grid, r, c, mx);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}