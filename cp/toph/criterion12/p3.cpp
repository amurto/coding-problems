#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
const int N = 2e5 + 5;

vector<int> lp(N + 1), pr;
void linear_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
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
        v = l.v * 1ll + r.v * 1ll;
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
        if (l <= tl && tr <= r)
            return t[v];
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

    // rupd = range update
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const int32_t &upd)
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
    void rupd(const int32_t &l, const int32_t &r, const int32_t &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

void solve()
{
    int n, q, t, l, r, g, x;
    cin >> n >> q;
    vector<int> arr(n);
    vector<set<int>> st(N);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        x = arr[i];
        while (x > 1)
        {
            int d = lp[x];
            st[d].insert(i);
            while (x % d == 0)
                x /= d;
        }
    }
    segtree<node> s(n);
    s.build(arr);
    while (q-- > 0)
    {
        cin >> t >> l >> r;
        l--;
        r--;
        if (t == 1)
            cout << s.query(l, r).v << "\n";
        else
        {
            cin >> g;
            while (g > 1)
            {
                int d = lp[g];
                auto it = st[d].lower_bound(l);
                if (it != st[d].end())
                {
                    vector<int> rem;
                    for (auto cur = it; cur != st[d].end() && *cur <= r; cur++)
                    {
                        int v = s.query(*cur, *cur).v;
                        v /= d;
                        s.rupd(*cur, *cur, v);
                        if (v % d > 0)
                            rem.pb(*cur);
                    }
                    for (int id : rem)
                        st[d].erase(id);
                }
                g /= d;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    solve();
    return 0;
}