// https://codeforces.com/contest/474/problem/F
// Ant colony

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct node
{
    vector<int> arr;
    int g = 0;
    node() {}
    node(int val)
    {
        g = val;
    }
    void merge(const node &l, const node &r)
    {
        g = __gcd(l.g, r.g);
        int sz1 = l.arr.size(), sz2 = r.arr.size();
        arr.resize(sz1 + sz2);
        int i = 0, j = 0, idx = 0;
        while (i < sz1 && j < sz2)
        {
            arr[idx++] = (l.arr[i] < r.arr[j]) ? l.arr[i++] : r.arr[j++];
        }
        while (i < sz1)
        {
            arr[idx++] = l.arr[i++];
        }
        while (j < sz2)
        {
            arr[idx++] = r.arr[j++];
        }
    }
};

template <typename node>
struct segtree
{
    int len;
    vector<node> t;
    segtree(int l)
    {
        len = l;
        t.resize(4 * len);
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v] = node(arr[tl]);
            t[v].arr.pb(arr[tl]);
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    // range gcd
    int gcdquery(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r)
    {
        if (l > tr || r < tl)
            return 0;
        if (tl >= l && tr <= r)
            return t[v].g;
        int32_t tm = (tl + tr) >> 1;
        return __gcd(gcdquery(v << 1, tl, tm, l, r), gcdquery(v << 1 | 1, tm + 1, tr, l, r));
    }

    // count number of e in given range
    int count(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, int e)
    {
        if (l > tr || r < tl)
            return 0;
        if (tl >= l && tr <= r)
        {
            int lb = lower_bound(t[v].arr.begin(), t[v].arr.end(), e) - t[v].arr.begin();
            int rb = upper_bound(t[v].arr.begin(), t[v].arr.end(), e) - t[v].arr.begin();
            if (lb > t[v].arr.size() || t[v].arr[lb] != e)
                return 0;
            return rb - lb;
        }
        int32_t tm = (tl + tr) >> 1;
        return count(v << 1, tl, tm, l, r, e) + count(v << 1 | 1, tm + 1, tr, l, r, e);
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    int gcdquery(const int32_t &l, const int32_t &r)
    {
        return gcdquery(1, 0, len - 1, l, r);
    }
    int count(const int32_t &l, const int32_t &r, int e)
    {
        return count(1, 0, len - 1, l, r, e);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, l, r;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    segtree<node> s(n);
    s.build(arr);
    cin >> m;
    while (m-- > 0)
    {
        cin >> l >> r;
        l--;
        r--;
        int g = s.gcdquery(l, r);
        cout << r - l + 1 - s.count(l, r, g) << "\n";
    }
    return 0;
}