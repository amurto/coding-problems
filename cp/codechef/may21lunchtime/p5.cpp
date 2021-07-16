#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 5;
int vis1[N], vis2[N], dep[N], ver[N], token[N];
vector<int> g[N];

struct node
{
    int id = 0, v = 0; // identity
    node() {}
    node(int idx, int val)
    {
        id = idx;
        v = val;
    }

    void merge(const node &l, const node &r)
    {
        v = max(l.v, r.v);
        if (l.v == r.v)
            id = max(l.id, r.id);
        else if (l.v > r.v)
            id = l.id;
        else
            id = r.id;
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
            t[v].id = ver[tl];
            t[v].v = arr[tl];
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
        if (l <= tl && tr <= r)
            return t[v];
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

    // rupd = range update
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const int &upd)
    {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r)
        {
            t[v].v = upd;
            return;
        }
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
    void rupd(const int32_t &l, const int32_t &r, const int &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

int set_timer(int cur, int t, int lvl)
{
    vis1[cur] = vis2[cur] = t;
    ver[vis1[cur]] = cur;
    dep[cur] = lvl;
    int mx = vis1[cur];
    for (int e : g[cur])
        vis2[cur] = set_timer(e, vis2[cur] + 1, lvl + 1);
    return vis2[cur];
}

ll dfs(segtree<node> &s, int cur)
{
    ll res = 0;
    for (int e : g[cur])
        res += dfs(s, e);
    if (token[cur] == 0)
    {
        node mx = s.query(vis1[cur], vis2[cur]);
        if (mx.v > dep[cur])
        {
            res += mx.v - dep[cur];
            s.rupd(vis1[mx.id], vis1[mx.id], 0);
            s.rupd(vis1[cur], vis1[cur], dep[cur]);
            token[cur] = 1;
            token[mx.id] = 0;
        }
    }
    return res;
}

ll solve()
{
    int n, p;
    string str;
    cin >> n >> str;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 2; i <= n; i++)
    {
        cin >> p;
        g[p].pb(i);
    }
    set_timer(1, 0, 1);
    for (int i = 1; i <= n; i++)
        token[i] = (str[i - 1] == '1');
    segtree<node> s(n);
    vector<int> tmp(n);
    for (int i = 0; i < n; i++)
        if (token[ver[i]])
            tmp[i] = dep[ver[i]];
    s.build(tmp);
    return dfs(s, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}