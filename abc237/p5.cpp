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

const int N = 2e5 + 5;
vector<pii> g[N];
ll H[N];

const ll inf = 1e16;
ll dijkstra(int n)
{
    vector<ll> dis(n + 1, 0);
    vector<bool> vis(n + 1);
    priority_queue<pii> pq;
    for (int i = 1; i <= n; i++)
        pq.push({0, i});
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        // d(cur.second, cur.first);
        if (!vis[cur.second])
        {
            vis[cur.second] = true;
            for (pii e : g[cur.second])
            {
                if (!vis[e.first] && dis[cur.second] + e.second > dis[e.first])
                {
                    dis[e.first] = dis[cur.second] + e.second;
                    pq.push({dis[e.first], e.first});
                }
            }
        }
    }
    return dis[1];
}

ll solve()
{
    int n, m;
    cin >> n >> m;
    ll res = 0;
    for (int i = 1; i <= n; i++)
        cin >> H[i];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (H[u] >= H[v])
        {
            g[u].pb({v, -2 * (H[u] - H[v])});
            g[v].pb({u, H[u] - H[v]});
        }
        else
        {
            g[u].pb({v, H[v] - H[u]});
            g[v].pb({u, -2 * (H[v] - H[u])});
        }
    }
    res = dijkstra(n);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}