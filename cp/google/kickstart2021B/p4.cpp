#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, ll>> piii;
#define pb push_back

const int N = 3e5 + 5;
vector<piii> g[N];
stack<int> wt[N];
vector<pii> query[N];

struct node
{
    ll v = 0;
    // identity
    node() {}
    node(ll val, int f)
    {
        v = val;
    }
    void merge(const node &l, const node &r)
    {
        v = __gcd(l.v, r.v);
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
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const ll &val)
    {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r)
        {
            t[v].v = val;
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        rupd(v << 1, tl, tm, l, r, val);
        rupd(v << 1 | 1, tm + 1, tr, l, r, val);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

public:
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void rupd(const int32_t &l, const int32_t &r, const ll &val)
    {
        rupd(1, 0, len - 1, l, r, val);
    }
};

void dfs(segtree<node> &s, vector<int> &unq, vector<ll> &res, int cur, int last)
{
    for (pii p : query[cur])
    {
        int idx = upper_bound(unq.begin(), unq.end(), p.first) - unq.begin();
        idx--;
        if (idx >= 0)
            res[p.second] = s.query(0, idx).v;
        else
            res[p.second] = 0;
    }
    for (piii e : g[cur])
    {
        if (e.first != last)
        {
            int w = e.second.first;
            int id = wt[w].top();
            wt[w].pop();
            s.rupd(id, id, e.second.second);
            dfs(s, unq, res, e.first, cur);
            s.rupd(id, id, 0);
            wt[w].push(id);
        }
    }
}

void solve()
{
    int n, q, u, v, w;
    ll a;
    cin >> n >> q;
    vector<int> unq;
    vector<ll> res(q);
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        query[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w >> a;
        g[u].pb({v, {w, a}});
        g[v].pb({u, {w, a}});
        unq.pb(w);
        while (!wt[w].empty())
            wt[w].pop();
    }
    sort(unq.begin(), unq.end());
    int sz = unq.size();
    for (int i = 0; i < sz; i++)
        wt[unq[i]].push(i);
    segtree<node> s(sz);
    for (int i = 0; i < q; i++)
    {
        cin >> u >> w;
        query[u].pb({w, i});
    }
    dfs(s, unq, res, 1, -1);
    for (int i = 0; i < q; i++)
        cout << res[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}