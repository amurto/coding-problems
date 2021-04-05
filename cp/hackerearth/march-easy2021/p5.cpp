#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void dfs(vector<vector<int>> &g, vector<int> &dis, int cur, int last, int d)
{
    dis[cur] = d;
    for (int e : g[cur])
        if (e != last)
            dfs(g, dis, e, cur, d + 1);
}

struct node
{
    ll v = 0; // identity
    node() {}
    node(ll val)
    {
        v = val;
    }
    void merge(const node &l, const node &r)
    {
        v = max(l.v, r.v);
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
        if (tl >= l && tr <= r)
            return t[v];
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

    // rupd = range update
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const ll &upd)
    {
        if (l > tr || r < tl)
            return;
        if (tl >= l && tr <= r)
        {
            t[v].v += upd;
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
    void rupd(const int32_t &l, const int32_t &r, const ll &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

void solve()
{
    int n, q, t, u, v;
    ll x;
    cin >> n;
    vector<ll> arr(n + 1), seq(n);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> ord(n), dis(n + 1), pos(n + 1);
    dfs(g, dis, 1, -1, 0);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int &i1, int &i2) {
        return dis[i1] < dis[i2];
    });
    for (int i = 0; i < n; i++)
    {
        seq[i] = arr[ord[i]];
        pos[ord[i]] = i;
    }
    segtree<node> s(n);
    s.build(seq);
    cin >> q;
    while (q-- > 0)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> u >> x;
            s.rupd(pos[u], pos[u], x);
        }
        else
        {
            cin >> x;
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + (r - l) / 2;
                if (x >= s.query(0, mid).v)
                    l = mid + 1;
                else
                    r = mid;
            }
            (s.query(l, l).v <= x) ? cout << "-1\n" : cout << dis[ord[l]] << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}