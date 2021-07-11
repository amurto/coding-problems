#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll pwr(ll x, int t)
{
    if (t == 0)
        return 1;
    return x * pwr(x, t - 1);
}

struct node
{
    ll v = 0; // identity
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

    // rupd = range update
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const ll &upd)
    {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r)
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
    int n, q, s, pos, l, r;
    ll p, val;
    cin >> n >> q >> p;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<segtree<node>> sg(5, segtree<node>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            ll tmp = pwr(arr[i], j) - pwr(arr[i] % p, j);
            ll cnt = 0;
            while (tmp > 0 && tmp % p == 0)
            {
                tmp /= p;
                cnt++;
            }
            sg[j].rupd(i, i, cnt);
        }
    }
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            cin >> pos >> val;
            pos--;
            arr[pos] = val;
            for (int j = 1; j <= 4; j++)
            {
                ll tmp = pwr(arr[pos], j) - pwr(arr[pos] % p, j);
                ll cnt = 0;
                while (tmp > 0 && tmp % p == 0)
                {
                    tmp /= p;
                    cnt++;
                }
                sg[j].rupd(pos, pos, cnt);
            }
        }
        else
        {
            cin >> s >> l >> r;
            l--;
            r--;
            cout << sg[s].query(l, r).v << " ";
        }
    }
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