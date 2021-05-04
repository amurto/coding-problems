// https://codeforces.com/contest/609/problem/E
// Minimum spanning tree for each edge

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

class edge
{
public:
    int u, v, w, id;
    edge() {}
    edge(int u, int v, int w, int id) : u(u), v(v), w(w), id(id) {}
    bool operator<(const edge &other) const
    {
        return w < other.w;
    }
};

const int N = 2e5 + 5, LGN = 19;
int up[N][LGN + 1], mx[N][LGN + 1], parent[N], cap[N], tin[N], tout[N], dep[N], timer = 0;
vector<pii> g[N];

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        cap[i] = 1;
    }
}

int root(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = root(parent[x]);
}

bool merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if (rx == ry)
        return false;
    // by size (capacity)
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
    return true;
}

void dfs(int cur, int last, int last_cost, int d)
{
    tin[cur] = ++timer;
    dep[cur] = d;
    up[cur][0] = last;
    mx[cur][0] = last_cost;
    for (int i = 1; i <= LGN; i++)
    {
        up[cur][i] = up[up[cur][i - 1]][i - 1];
        mx[cur][i] = max(mx[cur][i - 1], mx[up[cur][i - 1]][i - 1]);
    }
    for (pii e : g[cur])
        if (e.first != last)
            dfs(e.first, cur, e.second, d + 1);
    tout[cur] = timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LGN; i >= 0; i--)
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

int mx_edge(int u, int k)
{
    if (k == 0)
        return 0;
    int mxe = 0;
    for (int i = LGN; i >= 0; i--)
    {
        if ((1 << i) <= k)
        {
            mxe = max(mxe, mx[u][i]);
            u = up[u][i];
            k -= (1 << i);
        }
    }
    return mxe;
}

void solve()
{
    int n, m, u, v, w;
    cin >> n >> m;
    init(n);
    vector<edge> E(m);
    vector<bool> vis(m);
    vector<ll> res(m);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        E[i] = edge(u, v, w, i);
    }
    sort(E.begin(), E.end());
    ll cost = 0;
    for (int i = 0; i < m; i++)
    {
        vis[i] = merge(E[i].u, E[i].v);
        if (vis[i])
        {
            cost += 1ll * E[i].w;
            g[E[i].u].pb({E[i].v, E[i].w});
            g[E[i].v].pb({E[i].u, E[i].w});
        }
    }
    dfs(1, 1, 0, 0);
    for (int i = 0; i < m; i++)
    {
        if (vis[i])
            res[E[i].id] = cost;
        else
        {
            int anc = lca(E[i].u, E[i].v);
            res[E[i].id] = cost - max(mx_edge(E[i].u, dep[E[i].u] - dep[anc]), mx_edge(E[i].v, dep[E[i].v] - dep[anc])) + E[i].w;
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