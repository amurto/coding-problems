#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;
typedef pair<int, pair<ll, ll>> piii;
#define pb push_back

const ll inf = 1e18;
ll dijkstra(vector<vector<piii>> &g, int n, int x, int y)
{
    vector<int> vis(n + 1);
    auto cmp = [&](pii &p1, pii &p2) {
        return p1.second >= p2.second;
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
    pq.push({x, 0});
    while (!pq.empty())
    {
        pii tp = pq.top();
        pq.pop();
        int from = tp.first;
        ll d = tp.second;
        if (from == y)
            return d;
        if (vis[from])
            continue;
        vis[from] = true;
        for (piii e : g[from])
        {
            if (vis[e.first])
                continue;
            ll nd = 0, k = e.second.second;
            if (d % k != 0)
            {
                ll m = (d + k - 1) / k;
                m *= k;
                nd = m - d;
            }
            pq.push({e.first, d + nd + e.second.first});
        }
    }
    return inf;
}

ll solve()
{
    int n, m, x, y, u, v;
    ll t, k;
    cin >> n >> m >> x >> y;
    vector<vector<piii>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> t >> k;
        g[u].pb({v, {t, k}});
        g[v].pb({u, {t, k}});
    }
    ll d = dijkstra(g, n, x, y);
    return (d >= inf) ? -1 : d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}