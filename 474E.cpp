// https://codeforces.com/contest/474/problem/E
// Pillars

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
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const int &upd)
    {
        if (l > tr || r < tl)
            return;
        if (tl >= l && tr <= r)
        {
            t[v] = upd;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, cur = 1;
    ll d;
    cin >> n >> d;
    vector<ll> h(n + 1), st(n + 1);
    segtree<node> s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        st[i] = h[i];
    }
    sort(st.begin(), st.end());
    vector<int> l(n + 1), r(n + 1), dp(n + 1, 1), dir(n + 1);
    for (int i = n; i > 0; i--)
    {
        int idx = lower_bound(st.begin(), st.end(), h[i]) - st.begin();
        int ldx = upper_bound(st.begin(), st.end(), h[i] - d) - st.begin();
        ldx--;
        int rdx = lower_bound(st.begin(), st.end(), h[i] + d) - st.begin();
        if (ldx >= 0)
            l[i] = s.query(0, ldx).v;
        if (rdx <= n)
            r[i] = s.query(rdx, n).v;
        s.rupd(idx, idx, i);
    }
    for (int i = 1; i <= n; i++)
    {
        int mx = 0;
        if (l[i] > 0 && dp[i] + 1 > dp[l[i]])
            dp[l[i]] = dp[i] + 1;
        if (r[i] > 0 && dp[i] + 1 > dp[r[i]])
            dp[r[i]] = dp[i] + 1;
        vector<int> st;
    }
    cout << dp[cur] << "\n";
    while (cur > 0)
    {
        cout << cur << " ";
        cur = dir[cur];
    }
    return 0;
}