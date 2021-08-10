#ifdef amurto
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

struct node
{
    int v = 0, id = 0; // identity
    node() {}
    node(int val, int i)
    {
        v = val;
        id = i;
    }
    void merge(const node &l, const node &r)
    {
        v = l.v;
        id = l.id;
        if (l.v == r.v)
            id = max(l.id, r.id);
        else if (l.v < r.v)
        {
            v = r.v;
            id = r.id;
        }
    }
};

struct update
{
    int v = 0, id = 0;
    update() {}
    update(int val, int i)
    {
        v = val;
        id = i;
    }
    // combine the current update with the other update
    void combine(update &other, const int32_t &tl, const int32_t &tr)
    {
        if (other.v > v)
        {
            v = other.v;
            id = other.id;
        }
    }
    // store the correct information in the node x
    void apply(node &x, const int32_t &tl, const int32_t &tr)
    {
        if (v >= x.v)
        {
            x.v = v;
            x.id = id;
        }
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

    node query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r)
    {
        if (l > tr || r < tl)
            return identity_element;
        if (l <= tl && tr <= r)
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
        if (l <= tl && tr <= r)
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
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void rupd(const int32_t &l, const int32_t &r, const update &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

void solve()
{
    int n, m, row, l, r;
    cin >> n >> m;
    vector<vector<pii>> g(n + 1);
    vector<int> pts, last(n + 1), ids;
    for (int i = 0; i < m; i++)
    {
        cin >> row >> l >> r;
        g[row].pb({l, r});
        pts.pb(l);
        pts.pb(r);
    }
    sort(pts.begin(), pts.end());
    pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
    int sz = pts.size();
    segtree<node, update> s(sz);
    for (int i = 1; i <= n; i++)
    {
        node b = node(0, 0);
        for (pii p : g[i])
        {
            l = p.first;
            r = p.second;
            int l_id = lower_bound(pts.begin(), pts.end(), l) - pts.begin();
            int r_id = lower_bound(pts.begin(), pts.end(), r) - pts.begin();
            node e = s.query(l_id, r_id);
            b.merge(b, e);
        }
        last[i] = b.id;
        update upd = update(b.v + 1, i);
        for (pii p : g[i])
        {
            l = p.first;
            r = p.second;
            int l_id = lower_bound(pts.begin(), pts.end(), l) - pts.begin();
            int r_id = lower_bound(pts.begin(), pts.end(), r) - pts.begin();
            s.rupd(l_id, r_id, upd);
        }
    }
    vector<bool> vis(n + 1);
    node mx = s.query(0, sz - 1);
    int cur = mx.id;
    while (cur > 0)
    {
        vis[cur] = true;
        cur = last[cur];
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            ids.pb(i);
    cout << ids.size() << "\n";
    for (int id : ids)
        cout << id << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}