#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const ll inf = 1e17;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

ll bfs(vector<vector<ll>> &grid, vector<vector<ll>> &dis, ll w, int n, int m, int i, int j)
{
    queue<pii> q;
    q.push({i, j});
    vector<vector<bool>> vis(n, vector<bool>(m));
    vis[i][j] = true;
    dis[i][j] = 0;
    ll mn = inf, d = w;
    if (grid[i][j] > 0)
        mn = grid[i][j];
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            pii cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int ti = cur.first + di[dir], tj = cur.second + dj[dir];
                if (ti >= 0 && ti < n && tj >= 0 && tj < m && grid[ti][tj] != -1 && !vis[ti][tj])
                {
                    vis[ti][tj] = true;
                    dis[ti][tj] = d;
                    if (grid[ti][tj] > 0)
                        mn = min(mn, dis[ti][tj] + grid[ti][tj]);
                    q.push({ti, tj});
                }
            }
        }
        d += w;
    }
    return mn;
}

ll solve()
{
    int n, m;
    ll w;
    cin >> n >> m >> w;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    vector<vector<ll>> dis1(n, vector<ll>(m, inf)), dis2(n, vector<ll>(m, inf));
    ll p1 = bfs(grid, dis1, w, n, m, 0, 0), p2 = bfs(grid, dis2, w, n, m, n - 1, m - 1);
    ll res = min(dis1[n - 1][m - 1], p1 + p2);
    return (res >= inf) ? -1 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}