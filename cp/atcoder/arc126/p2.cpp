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
    void init(int l)
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

    // pupd = point update
    void pupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const int &upd)
    {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r)
        {
            t[v].v = max(t[v].v, upd);
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

int solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> g(n + 1, vector<vector<int>>(2));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][0].pb(b);
        if (a != b)
            g[b][1].pb(a);
    }
    vector<segtree<node>> dp(2);
    for (int j = 0; j < 2; j++)
        dp[j].init(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sort(g[i][j].rbegin(), g[i][j].rend());
            for (int x : g[i][j])
            {
                if (x <= i)
                {
                    if (x == i)
                    {
                        int mx = max(dp[0].query(0, i - 1).v, dp[1].query(0, i - 1).v) + 1;
                        dp[0].pupd(i, i, mx);
                        dp[1].pupd(i, i, mx);
                    }
                    else
                    {
                        int mx = dp[j ^ 1].query(0, x - 1).v + 1;
                        dp[j ^ 1].pupd(x, x, mx);
                        dp[j].pupd(i, i, mx);
                    }
                }
            }
        }
    }
    return max(dp[0].query(0, n).v, dp[1].query(0, n).v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}