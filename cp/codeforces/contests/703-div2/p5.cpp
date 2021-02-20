#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> piii;
#define pb push_back

const ll inf = 1e18;

ll sq(int a, int b)
{
    return a * 1ll * a + 2ll * a * b + b * 1ll * b;
}

void dijkstra(vector<vector<pii>> &g, vector<vector<ll>> &dis, int n)
{
    vector<vector<int>> vis(n + 1, vector<int>(51));
    auto cmp = [&](piii &p1, piii &p2) {
        if (p1.first == p2.first && p1.second.first == p2.second.first)
            return p1.second.second >= p2.second.second;
        return p1.first >= p2.first;
    };
    priority_queue<piii, vector<piii>, decltype(cmp)> pq(cmp);
    pq.push({0ll, {1, 0}});
    while (!pq.empty())
    {
        piii tp = pq.top();
        pq.pop();
        if (vis[tp.second.first][tp.second.second])
            continue;
        ll d = tp.first;
        int from = tp.second.first, wt = tp.second.second;
        vis[from][wt] = true;
        dis[from][wt] = d;
        for (pii e : g[from])
        {
            if (wt == 0)
            {
                if (vis[e.first][e.second])
                    continue;
                if (d < dis[e.first][e.second])
                {
                    dis[e.first][e.second] = d;
                    pq.push({d, {e.first, e.second}});
                }
            }
            else
            {
                if (vis[e.first][0])
                    continue;
                ll s = d + sq(wt, e.second);
                if (s < dis[e.first][0])
                {
                    dis[e.first][0] = s;
                    pq.push({d + sq(wt, e.second), {e.first, 0}});
                }
            }
        }
    }
}

void solve()
{
    int n, m, u, v, w;
    cin >> n >> m;
    vector<vector<pii>> g(n + 1);
    vector<vector<ll>> dis(n + 1, vector<ll>(51, inf));
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dijkstra(g, dis, n);
    for (int i = 1; i <= n; i++)
        if (dis[i][0] >= inf)
            cout << "-1 ";
        else
            cout << dis[i][0] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}