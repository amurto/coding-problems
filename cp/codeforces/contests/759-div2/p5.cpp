#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
    segtree() = default;

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
        if (l <= tl && tr <= r)
            return t[v];
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

    // pupd = point update
    void pupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const int &upd)
    {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r)
        {
            t[v].v += upd;
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        pupd(v << 1, tl, tm, l, r, upd);
        pupd(v << 1 | 1, tm + 1, tr, l, r, upd);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    // kth element from left
    // O(logn)
    int find_kth_left(const int32_t &v, const int32_t &tl, const int32_t &tr, const int k)
    {
        if (t[v].v == 0)
            return -1;
        if (tl == tr)
            return t[v].v >= k ? tl : -1;
        int32_t tm = (tl + tr) >> 1;
        if (t[v << 1].v >= k)
            return find_kth_left(v << 1, tl, tm, k);
        return find_kth_left(v << 1 | 1, tm + 1, tr, k - t[v << 1].v);
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
    void pupd(const int32_t &l, const int32_t &r, const int &upd)
    {
        pupd(1, 0, len - 1, l, r, upd);
    }
    int find_kth_left(const int k)
    {
        return find_kth_left(1, 0, len - 1, k);
    }
    int find_kth_right(const int k)
    {
        return find_kth_right(1, 0, len - 1, k);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1), par(n + 1), v(q), l(q), k(q), res(q, -1), cnt(n + 1);
    vector<vector<int>> g(n + 1), queries(n + 1);
    vector<set<int>> st(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 2; i <= n; i++)
    {
        cin >> par[i];
        g[par[i]].pb(i);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> v[i] >> l[i] >> k[i];
        queries[v[i]].pb(i);
    }
    segtree<node> s(n + 1);
    auto dfs = [&](const auto &self, int cur) -> void
    {
        if (cnt[arr[cur]] > 0)
        {
            st[cnt[arr[cur]]].erase(arr[cur]);
            s.pupd(cnt[arr[cur]], cnt[arr[cur]], -1);
        }
        cnt[arr[cur]]++;
        st[cnt[arr[cur]]].insert(arr[cur]);
        s.pupd(cnt[arr[cur]], cnt[arr[cur]], 1);
        for (int id : queries[cur])
        {
            int ans = s.find_kth_left(s.query(0, l[id] - 1).v + k[id]);
            if (ans >= 0)
                res[id] = *st[ans].begin();
        }
        for (int e : g[cur])
            self(self, e);

        st[cnt[arr[cur]]].erase(arr[cur]);
        s.pupd(cnt[arr[cur]], cnt[arr[cur]], -1);
        cnt[arr[cur]]--;
        if (cnt[arr[cur]] > 0)
        {
            st[cnt[arr[cur]]].insert(arr[cur]);
            s.pupd(cnt[arr[cur]], cnt[arr[cur]], 1);
        }
    };
    dfs(dfs, 1);
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
    while (t-- > 0)
        solve();
    return 0;
}