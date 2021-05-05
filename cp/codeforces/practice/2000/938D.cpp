// https://codeforces.com/contest/938/problem/D
// Buy a Ticket

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class node
{
public:
    int u;
    ll cost;
    node() {}
    node(int u, ll cost) : u(u), cost(cost) {}
    bool operator<(const node &other) const
    {
        return cost > other.cost;
    }
};

void solve()
{
    int n, m, u, v;
    ll w;
    cin >> n >> m;
    vector<vector<node>> g(n + 1);
    vector<ll> arr(n + 1), dis(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g[u].pb(node(v, 2*w));
        g[v].pb(node(u, 2*w));
    }
    priority_queue<node> pq;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dis[i] = arr[i];
        pq.push(node(i, dis[i]));
    }
    while (!pq.empty())
    {
        node cur = pq.top();
        pq.pop();
        if (vis[cur.u])
            continue;
        vis[cur.u] = true;
        for (node e : g[cur.u])
        {
            if (!vis[e.u] && cur.cost + e.cost < dis[e.u])
            {
                dis[e.u] = cur.cost + e.cost;
                pq.push(node(e.u, dis[e.u]));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}