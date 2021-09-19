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

int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int bfs(vector<vector<ll>> &dis, int bx, int by, int n)
{

    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));
    vis[bx][by] = true;
    dis[bx][by] = 0;
    queue<pii> q;
    q.push({bx, by});
    int mov = 1;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz > 0)
        {
            pii cur = q.front();
            q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int ti = cur.first + di[dir], tj = cur.second + dj[dir];
                if (ti > 0 && ti <= n && tj > 0 && tj <= n && !vis[ti][tj])
                {
                    vis[ti][tj] = true;
                    dis[ti][tj] = mov;
                    q.push({ti, tj});
                }
            }
            sz--;
        }
        mov++;
    }
    return mov;
}

ll solve()
{
    int n, ax, ay, bx, by;
    ll res = 0;
    cin >> n >> ax >> ay >> bx >> by;
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2 * n + 2, -1)));
    vector<vector<ll>> grid(n + 1, vector<ll>(n + 1)), dis(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> grid[i][j];
    int mov = bfs(dis, bx, by, n);
    dp[ax][ay][0] = 0;
    for (int t = 1; t <= mov; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][j] >= t - 1)
                {
                    for (int dir = 0; dir < 8; dir++)
                    {
                        int ti = i + di[dir], tj = j + dj[dir];
                        if (ti > 0 && ti <= n && tj > 0 && tj <= n && t - 1 < dis[ti][tj])
                        {
                            if (dp[ti][tj][t - 1] >= 0)
                                dp[i][j][t] = max(dp[i][j][t], dp[ti][tj][t - 1] + grid[i][j]);
                            res = max(res, dp[i][j][t]);
                        }
                    }
                }
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
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}