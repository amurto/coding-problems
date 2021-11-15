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

const ll inf = 1e18;
struct node
{
    ll v = inf; // identity
    node() {}
    node(ll val)
    {
        v = val;
    }
    void merge(const node &l, const node &r)
    {
        v = min(l.v, r.v);
    }
};

struct update
{
    ll v = 0;
    update() {}
    update(ll val)
    {
        v = val;
    }
    // combine the current update with the other update
    void combine(update &other, const int32_t &tl, const int32_t &tr)
    {
        v += other.v;
    }
    // store the correct information in the node x
    // apply x.v+=(tr-tl+1)*v for range addition and query sum
    void apply(node &x, const int32_t &tl, const int32_t &tr)
    {
        x.v += v;
    }
};

template <typename node, typename update>
struct segtree
{
    int len;
    vector<node> t;
    vector<update> u;
    vector<bool> lazy;
    node identity_element;
    update identity_transformation;
    segtree(int l)
    {
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node();
        identity_transformation = update();
    }
    segtree() = default;
    void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (!lazy[v])
            return;
        int32_t tm = (tl + tr) >> 1;
        apply(v << 1, tl, tm, u[v]);
        apply(v << 1 | 1, tm + 1, tr, u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }

    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd)
    {
        if (tl != tr)
        {
            lazy[v] = 1;
            u[v].combine(upd, tl, tr);
        }
        upd.apply(t[v], tl, tr);
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v].v = 0;
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
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

    // rupd = range update
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const update &upd)
    {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r)
        {
            apply(v, tl, tr, upd);
            return;
        }
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        rupd(v << 1, tl, tm, l, r, upd);
        rupd(v << 1 | 1, tm + 1, tr, l, r, upd);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    // kth element from left
    // O(logn)
    int find_kth_left(const int32_t &v, const int32_t &tl, const int32_t &tr, const int k)
    {
        // remove this in non lazy segment tree
        if (tl != tr)
            pushdown(v, tl, tr);
        if (t[v].v == 0)
            return -1;
        if (tl == tr)
            return tl;
        int32_t tm = (tl + tr) >> 1;
        if (t[v << 1].v >= k)
            return find_kth_left(v << 1, tl, tm, k);
        return find_kth_left(v << 1 | 1, tm + 1, tr, k - t[v << 1].v);
    }

    // kth element from right
    // O(logn)
    int find_kth_right(const int32_t &v, const int32_t &tl, const int32_t &tr, const int k)
    {
        if (tl != tr)
            pushdown(v, tl, tr);
        if (t[v].v == 0)
            return -1;
        if (tl == tr)
            return tl;
        int32_t tm = (tl + tr) >> 1;
        if (t[v << 1 | 1].v >= k)
            return find_kth_right(v << 1 | 1, tm + 1, tr, k);
        return find_kth_right(v << 1, tl, tm, k - t[v << 1 | 1].v);
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
    void rupd(const int32_t &l, const int32_t &r, const update &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
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

ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<ll> arr(n), dp(n);
    vector<int> last(n, -1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    segtree<node, update> s1(n), s2(n);
    s1.build(arr);
    s2.build(arr);
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            arr[i] = -arr[i];
        s1.rupd(0, i, arr[i]);
        int low = 0, high = i, mx = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (s1.query(mid, i).v <= 0)
            {
                mx = max(mx, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if (mx != -1 && s1.query(mx, i).v == 0)
            last[i] = max(last[i], mx);
        for (int i = 0; i < n; i++)
            cout << s1.query(i, i).v << " ";
        cout << "\n";
    }
    d(arr);
    for (int i = 0; i < n; i++)
    {
        arr[i] = -arr[i];
        s2.rupd(0, i, arr[i]);
        int low = 0, high = i, mx = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (s2.query(mid, i).v <= 0)
            {
                mx = max(mx, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if (mx != -1 && s2.query(mx, i).v == 0)
            last[i] = max(last[i], mx);
    }
    d(arr, last);
    for (int i = 0; i < n; i++)
    {
        if (last[i] >= 0)
        {
            if (last[i] == 0)
                dp[i] = 1;
            else
                dp[i] = 1 + dp[last[i] - 1];
        }
        res += dp[i];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}