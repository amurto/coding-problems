// https://codeforces.com/contest/276/problem/E
// Little Girl and Problem on Trees

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
vector<int> vis1(N), vis2(N), h(N);

struct node
{
    int v = 0; // identity
    node() {}
    node(int val)
    {
        v = val;
    }
    void merge(const node &l, const node &r)
    {
        v = l.v + r.v;
    }
};

struct update
{
    int v = 0;
    update() {}
    update(int val)
    {
        v = val;
    }
    // combine the current update with the other update
    void combine(update &other, const int32_t &tl, const int32_t &tr)
    {
        v += other.v;
    }
    // store the correct information in the node x
    void apply(node &x, const int32_t &tl, const int32_t &tr)
    {
        x.v += v;
    }
};

template <typename node, typename update>
struct segtree
{
    int len;
    vector<node> t;
    vector<update> u;
    vector<bool> lazy;
    node identity_element;
    update identity_transformation;
    segtree(int l)
    {
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node();
        identity_transformation = update();
    }

    void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (!lazy[v])
            return;
        int32_t tm = (tl + tr) >> 1;
        apply(v << 1, tl, tm, u[v]);
        apply(v << 1 | 1, tm + 1, tr, u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }

    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd)
    {
        if (tl != tr)
        {
            lazy[v] = 1;
            u[v].combine(upd, tl, tr);
        }
        upd.apply(t[v], tl, tr);
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v] = arr[tl];
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    node query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r)
    {
        if (l > tr || r < tl)
            return identity_element;
        if (tl >= l && tr <= r)
            return t[v];
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

    // rupd = range update
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const update &upd)
    {
        if (l > tr || r < tl)
            return;
        if (tl >= l && tr <= r)
        {
            apply(v, tl, tr, upd);
            return;
        }
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        rupd(v << 1, tl, tm, l, r, upd);
        rupd(v << 1 | 1, tm + 1, tr, l, r, upd);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void rupd(const int32_t &l, const int32_t &r, const update &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

int dfs(vector<vector<int>> &g, int cur, int last, int t, int lvl)
{
    vis1[cur] = vis2[cur] = t;
    h[cur] = lvl;
    if (g[cur].size() == 1 && g[cur][0] == last)
        return vis1[cur];
    int mx = vis1[cur];
    for (int e : g[cur])
    {
        if (e == last)
            continue;
        vis2[cur] = dfs(g, e, cur, vis2[cur] + 1, lvl + 1);
    }
    return vis2[cur];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, u, v, t, x, d;
    cin >> n >> q;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(g, 1, -1, 0, 0);
    segtree<node, update> tree(n), ht(n);
    while (q-- > 0)
    {
        cin >> t >> v;
        if (t == 0)
        {
            cin >> x >> d;
            int l = vis1[v] - d, r = min(vis1[v] + d, vis2[v]);
            if (h[v] - d <= 0)
            {
                int y = h[v] - d;
                y *= -1;
                ht.rupd(0, y, x);
                d -= y - 1;
                if (y >= h[v])
                    l = vis1[v] + y - h[v] + 1;
                else
                    l = vis1[v] - (h[v] - y) + 1;
            }
            if (l <= r)
                tree.rupd(l, r, x);
        }
        else
            cout << tree.query(vis1[v], vis1[v]).v + ht.query(h[v], h[v]).v << "\n";
    }
    return 0;
}