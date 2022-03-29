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

struct node
{
    int u, nat;
    ll c;
    node(int t_u, int t_nat, ll t_c)
    {
        u = t_u;
        nat = t_nat;
        c = t_c;
    }
    bool operator<(const node &other) const
    {
        return c > other.c;
    }
};

void solve()
{
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    vector<int> nation(n + 1), vis(n + 1);
    vector<ll> res(n + 1, inf);
    vector<bool> is_popular(n + 1);
    vector<vector<pii>> g(n + 1), dis(n + 1, vector<pii>(2, {inf, inf}));
    for (int i = 1; i <= n; i++)
        cin >> nation[i];
    for (int i = 0; i < l; i++)
    {
        int v;
        cin >> v;
        is_popular[v] = true;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        g[u].pb({v, c});
        g[v].pb({u, c});
    }
    priority_queue<node> pq;
    for (int i = 1; i <= n; i++)
        if (is_popular[i])
            pq.push(node(i, nation[i], 0));
    while (!pq.empty())
    {
        node cur = pq.top();
        pq.pop();
        if (vis[cur.u] >= 0 && vis[cur.u] != cur.nat)
        {
            if (vis[cur.u] == 0)
            {
                vis[cur.u] = cur.nat;
                if (cur.nat != nation[cur.u])
                    res[cur.u] = min(res[cur.u], cur.c);
            }
            else
            {
                vis[cur.u] = -1;
                if (cur.nat != nation[cur.u])
                    res[cur.u] = min(res[cur.u], cur.c);
            }
            for (pii e : g[cur.u])
                pq.push(node(e.first, cur.nat, cur.c + e.second));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (res[i] >= inf)
            res[i] = -1;
        cout << res[i] << " ";
    }
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