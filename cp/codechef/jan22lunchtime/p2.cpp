#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int inf = 4e5 + 5;
bool has_range(int l, int r, int i)
{
    if (l > r)
    {
        if (i >= l || i <= r)
            return true;
        return false;
    }
    return (i >= l && i <= r);
}

struct node
{
    int v = inf, id = -1;
    ll s = 0;
    node() {}
    node(int val, ll sum)
    {
        v = val;
        s = sum;
    }
    void merge(const node &l, const node &r)
    {
        v = min(l.v, r.v);
        if (l.v < r.v)
            id = l.id;
        else
            id = r.id;
        s = l.s + r.s;
    }
};

struct update
{
    int v = 0;
    update() {}
    update(int val)
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
        x.s += (tr - tl + 1) * 1ll * v;
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
            t[v].v = arr[tl];
            t[v].s = arr[tl];
            t[v].id = tl;
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
            return t[v].v >= k ? tl : -1;
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
            return t[v].v >= k ? tl : -1;
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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), res(n, -1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> seq = arr;
    segtree<node, update> s(n);

    auto cmp = [&](int i1, int i2)
    {
        return !has_range(i1, ((i1 + k) % n), i2);
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            pq.push(i);
            arr[i] = inf;
        }
    }
    s.build(arr);
    int val = 1, cnt = 0;
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        res[cur] = val;
        val++;
        cnt++;
        int l = cur - k, r = cur - 1;
        if (l < 0)
            l += n;
        if (l < r)
        {
            // [l,r]
            s.rupd(l, r, -1);
            bool f = true;
            while (f)
            {
                node qr = s.query(l, r);
                if (qr.v == 0)
                {
                    pq.push(qr.id);
                    s.rupd(qr.id, qr.id, inf);
                }
                else
                    f = false;
            }
        }
        else
        {
            // [0,r]
            s.rupd(0, r, -1);
            bool f = true;
            while (f)
            {
                node qr = s.query(0, r);
                if (qr.v == 0)
                {
                    pq.push(qr.id);
                    s.rupd(qr.id, qr.id, inf);
                }
                else
                    f = false;
            }

            // [l,n-1]
            s.rupd(l, n - 1, -1);
            f = true;
            while (f)
            {
                node qr = s.query(l, n - 1);
                if (qr.v == 0)
                {
                    pq.push(qr.id);
                    s.rupd(qr.id, qr.id, inf);
                }
                else
                    f = false;
            }
        }
    }
    if (cnt < n)
    {
        cout << "-1\n";
        return;
    }
    auto check_valid = [&]()
    {
        segtree<node, update> st(n + 1);
        for (int j = 0; j < k; j++)
            st.rupd(res[j], res[j], 1);
        for (int i = 0; i < n; i++)
        {
            int r = (i + k) % n;
            st.rupd(res[r], res[r], 1);
            if (st.query(1, res[i]).s - 1 != seq[i])
                return false;
            st.rupd(res[i], res[i], -1);
        }
        return true;
    };
    for (int i = 0; i < n; i++)
    {
        if (res[i] == -1)
        {
            cout << "-1\n";
            return;
        }
    }
    if (!check_valid())
    {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++)
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