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

const ll inf = 1e16;
vector<ll> dijkstra(vector<vector<pii>> &g, int n)
{
    vector<ll> dis(n + 1, inf);
    vector<bool> vis(n + 1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        if (!vis[cur.second])
        {
            vis[cur.second] = true;
            for (pii e : g[cur.second])
            {
                if (!vis[e.first] && dis[cur.second] + e.second < dis[e.first])
                {
                    dis[e.first] = dis[cur.second] + e.second;
                    pq.push({dis[e.first], e.first});
                }
            }
        }
    }
    return dis;
}

ll solve()
{
    int n, m;
    cin >> n >> m;
    ll res = 0;
    vector<vector<pii>> g(n + 1);
    vector<ll> H(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> H[i];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (H[u] < H[v])
            swap(u, v);
        g[u].pb({v, 0});
        g[v].pb({u, H[u] - H[v]});
    }
    vector<ll> dis = dijkstra(g, n);
    for (int i = 2; i <= n; i++)
        if (H[1] > H[i])
            res = max(res, H[1] - H[i] - dis[i]);
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