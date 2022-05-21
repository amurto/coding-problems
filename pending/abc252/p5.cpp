#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

const ll inf = 1e18;
struct edge
{
    int v, c, id;
    edge(int vv, int cc, int idd)
    {
        v = vv;
        c = cc;
        id = idd;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n + 1);
    vector<int> last(n + 1, -1);
    vector<ll> dis(n + 1, inf);
    vector<bool> vis(n + 1), vis_edge(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].pb(edge(v, c, i));
        g[v].pb(edge(u, c, i));
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dis[1] = 0;
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        if (!vis[cur.second])
        {
            vis[cur.second] = true;
            if (last[cur.second] >= 0)
                vis_edge[last[cur.second]] = true;
            for (edge e : g[cur.second])
            {
                if (!vis[e.v] && cur.first + e.c < dis[e.v])
                {
                    dis[e.v] = cur.first + e.c;
                    pq.push({dis[e.v], e.v});
                    last[e.v] = e.id;
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
        if (vis_edge[i])
            cout << i + 1 << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}