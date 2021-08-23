// https://codeforces.com/contest/960/problem/F
// Pathwalks

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
    segtree() = default;
    void init(int l)
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
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const int &upd)
    {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r)
        {
            t[v].v = max(t[v].v, upd);
            return;
        }
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
    void rupd(const int32_t &l, const int32_t &r, const int &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

int solve()
{
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> a(m), b(m), w(m), dp(m), sz(n + 1);
    vector<vector<int>> wts(n + 1);
    for (int i = 1; i <= n; i++)
        wts[i].pb(0);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> w[i];
        wts[b[i]].pb(w[i]);
    }
    vector<segtree<node>> s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        sort(wts[i].begin(), wts[i].end());
        wts[i].resize(unique(wts[i].begin(), wts[i].end()) - wts[i].begin());
        sz[i] = wts[i].size();
        s[i].init(sz[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int id1 = lower_bound(wts[a[i]].begin(), wts[a[i]].end(), w[i]) - wts[a[i]].begin();
        dp[i] = s[a[i]].query(0, id1 - 1).v + 1;
        int id2 = lower_bound(wts[b[i]].begin(), wts[b[i]].end(), w[i]) - wts[b[i]].begin();
        s[b[i]].rupd(id2, id2, dp[i]);
        res = max(res, dp[i]);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}