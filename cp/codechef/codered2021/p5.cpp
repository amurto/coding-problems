#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 1e5 + 5, b = 17;

int timer;
vector<int> arr(N), vis1(N), vis2(N), tin, tout;
vector<vector<int>> up;
vector<pii> st;

pii pmx(pii &p1, pii &p2)
{
    if (p1.first == -1)
        return p2;
    if (p2.first == -1)
        return p1;
    if (p1.first > p2.first)
        return p1;
    return p2;
}

void lca_dfs(vector<vector<int>> &g, int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= b; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (int u : g[v])
        if (u != p)
            lca_dfs(g, u, v);
    tout[v] = ++timer;
}

// Entry and Exit time for Segment Tree
int dfs(vector<vector<int>> &g, int cur, int last, int t)
{
    vis1[cur] = vis2[cur] = t;
    st.pb({arr[cur], cur});
    if (g[cur].size() == 1 && g[cur][0] == last)
        return vis1[cur];
    int mx = vis1[cur];
    for (int e : g[cur])
        if (e != last)
            vis2[cur] = dfs(g, e, cur, vis2[cur] + 1);
    return vis2[cur];
}

bool is_ancestor(int u, int v)
{
    return vis1[u] <= vis1[v] && vis2[u] >= vis2[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = b; i >= 0; --i)
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

void preprocess(vector<vector<int>> &g, int n, int root)
{
    tin.resize(n + 1);
    tout.resize(n + 1);
    timer = 0;
    up.assign(n + 1, vector<int>(b + 1));
    lca_dfs(g, root, root);
}

struct node
{
    set<pii> st; // identity
    node() {}
    void merge(const node &l, const node &r)
    {
        for (pii p : l.st)
            st.insert(p);
        for (pii p : r.st)
            st.insert(p);
    }
};

template <typename node>
struct segtree
{
    int len;
    vector<node> t;
    node identity_element;
    segtree(int l)
    {
        len = l;
        t.resize(4 * len);
        identity_element = node();
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v].st.insert(arr[tl]);
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    pii query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const int32_t &val)
    {
        if (l > tr || r < tl)
            return {-1, -1};
        if (l <= tl && tr <= r)
        {
            auto it = t[v].st.lower_bound({val, -1});
            it--;
            if (it == t[v].st.end())
                return {-1, -1};
            return *it;
        }
        int32_t tm = (tl + tr) >> 1;
        pii a = query(v << 1, tl, tm, l, r, val), b = query(v << 1 | 1, tm + 1, tr, l, r, val);
        return pmx(a, b);
    }

    // rupd = range update
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &idx, const int &x, const int &old, const int &nw)
    {
        if (idx > tr || idx < tl)
            return;
        if (idx <= tl && idx <= tr)
        {
            t[v].st.erase(t[v].st.find({old, x}));
            t[v].st.insert({nw, x});
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        rupd(v << 1, tl, tm, idx, x, old, v);
        rupd(v << 1 | 1, tm + 1, tr, idx, x, old, v);
        t[v].st.erase(t[v].st.find({old, x}));
        t[v].st.insert({nw, x});
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    pii query(const int32_t &l, const int32_t &r, const int &val)
    {
        return query(1, 0, len - 1, l, r, val);
    }
    void rupd(const int32_t &idx, const int &x, const int &old, const int &nw)
    {
        rupd(1, 0, len - 1, idx, x, old, nw);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, u, v, x, t;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    preprocess(g, n, 1);
    dfs(g, 1, -1, 0);
    segtree<node> s(n);
    s.build(st);
    while (q-- > 0)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x;
            pii n1 = s.query(0, n - 1, arr[x]), e = {-1, -1};
            if (n1.first == -1)
            {
                cout << "-1\n";
                continue;
            }
            int ancestor = lca(x, n1.second);
            if (ancestor == x)
            {
                pii e1 = {-1, -1}, e2 = {-1, -1};
                if (vis1[x] > 0)
                    e1 = s.query(0, vis1[x] - 1, arr[x]);
                if (vis2[x] < n - 1)
                    e2 = s.query(vis2[x] + 1, n - 1, arr[x]);
                e = pmx(e1, e2);
            }
            else
            {
                e = s.query(vis1[x], vis2[x], arr[x]);
            }
            if (e.first == -1)
                cout << "-1\n";
            else
                cout << n1.first * 1ll * e.first << "\n";
        }
        else
        {
            cin >> u >> v;
            s.rupd(vis1[u], u, arr[u], v);
            arr[u] = v;
        }
    }
    return 0;
}