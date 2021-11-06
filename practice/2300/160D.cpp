// https://codeforces.com/contest/160/problem/D
// Edges in MST

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

class edge
{
public:
    int u, v, id;
    ll w;
    edge() {}
    edge(int u, int v, ll w, int id) : u(u), v(v), w(w), id(id) {}
    bool operator<(const edge &other) const
    {
        return w < other.w;
    }
};

const int N = 1e5 + 5;
vector<edge> g[N];
int bin[N], bout[N], mn_time[N];
bool b_vis[N];

struct dsu
{
    int n;
    vector<int> parent, cap;
    dsu(int l)
    {
        n = l;
        parent.resize(n + 1);
        cap.resize(n + 1);
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

    void merge(int x, int y)
    {
        int rx = root(x), ry = root(y);
        if (rx == ry)
            return;
        // by size (capacity)
        if (cap[rx] < cap[ry])
            swap(rx, ry);
        cap[rx] += cap[ry];
        parent[ry] = parent[rx];
    }
};

vector<int> find_bridges(set<int> nodes)
{
    vector<int> bridge_ids;
    auto preorder_dfs = [&](const auto &self, int cur, int par, int t) -> int
    {
        bin[cur] = bout[cur] = mn_time[cur] = t;
        b_vis[cur] = true;
        for (edge e : g[cur])
        {
            if (!b_vis[e.v])
            {
                bout[cur] = self(self, e.v, e.id, bout[cur] + 1);
                mn_time[cur] = min(mn_time[cur], mn_time[e.v]);
                // check for bridge
                if (mn_time[e.v] > bin[cur])
                    bridge_ids.pb(e.id);
            }
            else if (e.id != par)
                mn_time[cur] = min(mn_time[cur], bin[e.v]);
        }
        return bout[cur];
    };
    for (int x : nodes)
    {
        b_vis[x] = false;
        bin[x] = bout[x] = mn_time[x] = 0;
    }
    for (int x : nodes)
        if (!b_vis[x])
            preorder_dfs(preorder_dfs, x, -1, 1);
    return bridge_ids;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<edge> edges;
    vector<int> res(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.pb(edge(u, v, w, i));
    }
    dsu st = dsu(n);
    sort(edges.begin(), edges.end());
    for (int i = 0; i < m;)
    {
        int r = i;
        set<int> nodes;
        while (r < m && edges[i].w == edges[r].w)
        {
            if (st.root(edges[r].u) != st.root(edges[r].v))
            {
                res[edges[r].id] = 1;
                nodes.insert(st.root(edges[r].u));
                nodes.insert(st.root(edges[r].v));
            }
            r++;
        }
        for (int x : nodes)
            g[x].clear();
        for (int j = i; j < r; j++)
        {
            if (res[edges[j].id] == 1)
            {
                g[st.root(edges[j].u)].pb(edge(st.root(edges[j].u), st.root(edges[j].v), edges[j].w, edges[j].id));
                g[st.root(edges[j].v)].pb(edge(st.root(edges[j].v), st.root(edges[j].u), edges[j].w, edges[j].id));
            }
        }
        vector<int> bridge_ids = find_bridges(nodes);
        for (int x : bridge_ids)
            res[x] = 2;
        while (i < r)
        {
            st.merge(edges[i].u, edges[i].v);
            i++;
        }
    }
    for (int i = 0; i < m; i++)
        if (res[i] == 0)
            cout << "none\n";
        else if (res[i] == 1)
            cout << "at least one\n";
        else
            cout << "any\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}