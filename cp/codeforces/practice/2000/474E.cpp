// https://codeforces.com/contest/474/problem/E
// Pillars

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct node
{
    int v = 0, idx = 0; // identity
    node() {}
    void merge(const node &l, const node &r)
    {
        idx = (l.v > r.v) ? l.idx : r.idx;
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
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const pair<int, int> &p)
    {
        if (l > tr || r < tl)
            return;
        if (tl >= l && tr <= r)
        {
            t[v].v = p.first;
            t[v].idx = p.second;
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        rupd(v << 1, tl, tm, l, r, p);
        rupd(v << 1 | 1, tm + 1, tr, l, r, p);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

public:
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void rupd(const int32_t &l, const int32_t &r, const pair<int, int> &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll d;
    cin >> n >> d;
    vector<ll> h(n + 1), st;
    vector<int> dp(n + 1), dir(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        st.pb(h[i]);
    }
    sort(st.begin(), st.end());
    st.resize(unique(st.begin(), st.end()) - st.begin());
    int m = st.size();
    segtree<node> s(m);
    for (int i = n; i > 0; i--)
    {
        int idx = lower_bound(st.begin(), st.end(), h[i]) - st.begin();
        int ldx = upper_bound(st.begin(), st.end(), h[i] - d) - st.begin();
        int rdx = lower_bound(st.begin(), st.end(), h[i] + d) - st.begin();
        node l = (ldx - 1 >= 0) ? s.query(0, ldx - 1) : node();
        node r = (rdx < m) ? s.query(rdx, m - 1) : node();
        node ans = node();
        ans.merge(l, r);
        dp[i] = ans.v + 1;
        dir[i] = ans.idx;
        s.rupd(idx, idx, {dp[i], i});
    }
    int cur = s.query(0, m - 1).idx;
    cout << dp[cur] << "\n";
    while (cur > 0)
    {
        cout << cur << " ";
        cur = dir[cur];
    }
    return 0;
}