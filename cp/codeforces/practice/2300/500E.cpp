// https://codeforces.com/contest/500/problem/E
// New Year Domino

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

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
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void rupd(const int32_t &l, const int32_t &r, const update &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, x, y;
    cin >> n;
    vector<int> p(n), h(n);
    for (int i = 0; i < n; i++)
        cin >> p[i] >> h[i];
    cin >> q;
    vector<int> res(q);
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        mp[x - 1].pb({y - 1, i});
    }
    segtree<node, update> s(n);
    stack<pii> st;
    for (int i = n - 2; i >= 0; i--)
    {
        int r = p[i] + h[i];
        if (r < p[i + 1])
        {
            st.push({r, i + 1});
            s.rupd(i + 1, i + 1, p[i + 1] - r);
        }
        while (!st.empty() && r > st.top().first)
        {
            pii tp = st.top();
            st.pop();
            s.rupd(tp.second, tp.second, -(p[tp.second] - tp.first));
            if (r < p[tp.second])
            {
                st.push({r, tp.second});
                s.rupd(tp.second, tp.second, p[tp.second] - r);
            }
        }
        for (pii y : mp[i])
            res[y.second] = s.query(i, y.first).v;
    }
    for (int r : res)
        cout << r << "\n";
    return 0;
}