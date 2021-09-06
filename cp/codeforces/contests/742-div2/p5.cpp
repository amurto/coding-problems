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
    // identity
    int lt = 0, rt = 0, pre = 0, suf = 0, lv = 0, rv = 0;
    ll sum = 0;
    node() {}
    void merge(const node &l, const node &r)
    {
        if (l.sum == 0)
        {
            lt = r.lt;
            rt = r.rt;
            pre = r.pre;
            suf = r.suf;
            lv = r.lv;
            rv = r.rv;
            sum = r.sum;
        }
        else if (r.sum == 0)
        {
            lt = l.lt;
            rt = l.rt;
            pre = l.pre;
            suf = l.suf;
            lv = l.lv;
            rv = l.rv;
            sum = l.sum;
        }
        else
        {
            lt = l.lt;
            rt = r.rt;
            pre = l.pre;
            suf = r.suf;
            lv = l.lv;
            rv = r.rv;
            sum = l.sum + r.sum;
            if (l.rv <= r.lv)
            {
                sum += (1ll * (l.rt - l.suf + 1) * (r.pre - r.lt + 1));
                if (l.suf == l.lt && r.pre == r.rt)
                {
                    pre = rt;
                    suf = lt;
                }
                else if (l.suf == l.lt)
                    pre = r.pre;
                else if (r.pre == r.rt)
                    suf = l.suf;
            }
        }
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
            t[v].lt = tl;
            t[v].rt = tr;
            t[v].pre = tl;
            t[v].suf = tr;
            t[v].lv = arr[tl];
            t[v].rv = arr[tr];
            t[v].sum = 1ll;
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
            t[v].lv = upd;
            t[v].rv = upd;
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        pupd(v << 1, tl, tm, l, r, upd);
        pupd(v << 1 | 1, tm + 1, tr, l, r, upd);
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
    void pupd(const int32_t &l, const int32_t &r, const int &upd)
    {
        pupd(1, 0, len - 1, l, r, upd);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    segtree<node> s(n);
    s.build(arr);
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            s.pupd(x - 1, x - 1, y);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << s.query(l - 1, r - 1).sum << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}