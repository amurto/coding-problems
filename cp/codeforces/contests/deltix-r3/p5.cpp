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

const int inf = 1e9 + 7;
struct node
{
    int v = inf; // identity
    node() {}
    node(int val)
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

void solve()
{
    int n, q, abc = 0;
    string str;
    cin >> n >> q >> str;
    vector<int> ids(q), res(q, inf);
    vector<char> ch(q);
    for (int i = 0; i < q; i++)
    {
        cin >> ids[i] >> ch[i];
        ids[i]--;
    }
    vector<string> curs = {"ab", "ac", "bc"};
    for (string cur : curs)
    {
        vector<int> pre(n), suf(n), arr(n);
        array<int, 3> cnt{0, 0, 0};
        for (char c : str)
            cnt[c - 'a']++;
        pre[0] = (str[0] == cur[0]);
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + (str[i] == cur[0]);
        suf[n - 1] = (str[n - 1] == cur[1]);
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] + (str[i] == cur[1]);
        for (int i = 0; i < n; i++)
        {
            arr[i] = pre[i];
            if (i + 1 < n)
                arr[i] += suf[i + 1];
        }
        segtree<node, update> s(n);
        s.build(arr);
        for (int i = 0; i < q; i++)
        {
            cnt[str[ids[i]] - 'a']--;
            if (str[ids[i]] == cur[0])
                s.rupd(ids[i], n - 1, -1);
            if (ids[i] > 0 && str[ids[i]] == cur[1])
                s.rupd(0, ids[i] - 1, -1);
            str[ids[i]] = ch[i];
            cnt[str[ids[i]] - 'a']++;
            if (str[ids[i]] == cur[0])
                s.rupd(ids[i], n - 1, 1);
            if (ids[i] > 0 && str[ids[i]] == cur[1])
                s.rupd(0, ids[i] - 1, 1);
            res[i] = min(res[i], s.query(0, n - 1).v);
            res[i] = min(res[i], cnt[cur[1] - 'a']);
        }
    }
    for (int i = 0; i < q; i++)
        cout << res[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}