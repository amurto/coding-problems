#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e7;
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
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const int &upd)
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
    void rupd(const int32_t &l, const int32_t &r, const int &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

int solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<int> arr(m), h(m, -1), con(m, -1);
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (grid[i][j] == '#')
            {
                h[j] = i;
                break;
            }
        }
        if (h[j] >= 0)
        {
            int c = h[j];
            while (c < n && grid[c][j] == '#')
                c++;
            con[j] = c - 1;
        }
    }
    vector<int> l(m), r(m);
    for (int i = 1; i < m; i++)
    {
        l[i] = i;
        if (h[i] != -1)
        {
            if (h[i] <= con[i - 1])
                l[i] = l[i - 1];
        }
    }
    r[m - 1] = m - 1;
    for (int i = m - 2; i >= 0; i--)
    {
        r[i] = i;
        if (h[i] != -1)
        {
            if (h[i] <= con[i + 1])
                r[i] = r[i + 1];
        }
    }
    vector<vector<int>> ivs(m);
    for (int i = 0; i < m; i++)
        ivs[r[i]].pb(l[i]);
    vector<int> dp(m, m + 1);
    segtree<node> s(m);
    s.build(dp);
    for (int i = 0; i < m; i++)
    {
        for (int e : ivs[i])
        {
            int last = 0;
            if (e - 1 >= 0)
                last = dp[e - 1];
            dp[i] = min(dp[i], 1 + min(last, s.query(e, i).v));
        }
        s.rupd(i, i, dp[i]);
    }
    // for (int i = 0; i < m; i++)
    //     cout << i << " -> " << dp[i] << "\n";
    return dp[m - 1] - count(h.begin(), h.end(), -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}