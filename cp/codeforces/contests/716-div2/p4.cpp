#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct node
{
    int v = 0, freq = 0; // identity
    node() {}
    node(int val, int cnt)
    {
        v = val;
        freq = cnt;
    }
    void merge(const node &l, const node &r)
    {
        if (l.v == r.v)
        {
            v = l.v;
            freq = l.freq + r.freq;
        }
        else
        {
            if (l.freq > r.freq)
            {
                v = l.v;
                freq = l.freq - r.freq;
            }
            else
            {
                v = r.v;
                freq = r.freq - l.freq;
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

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v] = node(arr[tl], 1);
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
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<vector<int>> st(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        st[arr[i]].pb(i);
    }
    segtree<node> s(n);
    s.build(arr);
    while (q-- > 0)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        node e = s.query(l, r);
        int lb = lower_bound(st[e.v].begin(), st[e.v].end(), l) - st[e.v].begin();
        int ub = upper_bound(st[e.v].begin(), st[e.v].end(), r) - st[e.v].begin();
        int cnt = ub - lb;
        int rem = r - l + 1 - cnt;
        int u = min(cnt, rem + 1);
        cout << 1 + cnt - u << "\n";
    }
    return 0;
}