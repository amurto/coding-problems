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
    int v = 0, id = -1; // identity
    node() {}
    node(int val, int idx)
    {
        v = val;
        id = idx;
    }
    void merge(const node &l, const node &r)
    {
        if (l.v == r.v)
        {
            v = l.v;
            id = max(l.id, r.id);
        }
        else if (l.v > r.v)
        {
            v = l.v;
            id = l.id;
        }
        else
        {
            v = r.v;
            id = r.id;
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
    void pupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const node upd)
    {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r)
        {
            t[v].merge(t[v], upd);
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        pupd(v << 1, tl, tm, l, r, upd);
        pupd(v << 1 | 1, tm + 1, tr, l, r, upd);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

public:
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void pupd(const int32_t &l, const int32_t &r, const node upd)
    {
        pupd(1, 0, len - 1, l, r, upd);
    }
};

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n), ids(n), is_lis(n), is_lds(n), last_lis(n, -1), last_lds(n, -1), dp1(n), dp2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i]--;
    }
    iota(ids.begin(), ids.end(), 0);
    segtree<node> lis(n), lds(n);
    int best_lis = 0;
    for (int i = 0; i < n; i++)
    {
        node mx = lis.query(0, arr[i]);
        dp1[i] = mx.v + 1;
        last_lis[i] = mx.id;
        lis.pupd(arr[i], arr[i], node(dp1[i], i));
        best_lis = max(best_lis, dp1[i]);
    }
    for (int i = 0; i < n; i++)
        if (dp1[i] == best_lis)
            is_lis[i] = 1;
    for (int i = n - 1; i >= 0; i--)
        if (is_lis[i] && last_lis[i] != -1)
            is_lis[last_lis[i]] = 1;
    int best_lds = 0;
    for (int i = 0; i < n; i++)
    {
        node mx = lds.query(arr[i], n - 1);
        dp2[i] = mx.v + 1;
        last_lds[i] = mx.id;
        lds.pupd(arr[i], arr[i], node(dp2[i], i));
        best_lds = max(best_lds, dp2[i]);
    }
    for (int i = n - 1; i >= 0; i--)
        if (dp2[i] == best_lds)
            is_lds[i] = 1;
    for (int i = n - 1; i >= 0; i--)
        if (is_lds[i] && last_lds[i] != -1)
            is_lds[last_lds[i]] = 1;
    // vector<int> dp(n), last(n, -1);
    // for (int i = 0; i < n; i--)
    // {
    //     if (is_lis[i] && is_lds[i])
    //     {
    //         dp[i] = 1;
    //         if (last[i] >= 0 && is_lis[last[i]] && is_lds[last[i]])
    //             dp[i] = dp[last[i]] + 1;
    //     }
    //     last[arr[i]] = i;
    //     res = max(res, dp[i]);
    // }
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