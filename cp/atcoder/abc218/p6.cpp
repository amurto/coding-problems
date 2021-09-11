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

const int N = 405;
int adj[N][N], ids[N][N];
int last[N];
vector<pii> edges;

int bfs(int n)
{
    vector<bool> vis(n + 1);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    int dis = 1;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz > 0)
        {
            int cur = q.front();
            q.pop();
            for (int i = 1; i <= n; i++)
            {
                if (adj[cur][i] && !vis[i])
                {
                    last[i] = cur;
                    vis[i] = true;
                    q.push(i);
                    if (i == n)
                        return dis;
                }
            }
            sz--;
        }
        dis++;
    }
    return -1;
}

void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<int> res(m, -1), mark(m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        edges.pb({u, v});
        adj[u][v] = 1;
        ids[u][v] = i;
    }
    int dis = bfs(n);
    if (dis >= 0)
    {
        int cur = n;
        while (cur != 1)
        {
            mark[ids[last[cur]][cur]] = 1;
            cur = last[cur];
        }
        for (int i = 0; i < m; i++)
        {
            if (mark[i])
            {
                adj[edges[i].first][edges[i].second] = 0;
                res[i] = bfs(n);
                adj[edges[i].first][edges[i].second] = 1;
            }
            else
                res[i] = dis;
        }
    }
    for (int i = 0; i < m; i++)
        cout << res[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}