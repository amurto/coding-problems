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

const int N = 1e5 + 5, inf = 1e9 + 5;
vector<int> g[N];
int arr[N], dp[N];
vector<int> seq;

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
            t[v].v += upd;
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

int bs(segtree<node> &s, int k)
{
    int n = s.len;
    int low = 0, high = n - 1, res = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (s.query(0, mid).v >= k)
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

int dfs(segtree<node> &s, int cur, int last, int h)
{
    int id = lower_bound(seq.begin(), seq.end(), arr[cur]) - seq.begin();
    s.pupd(id, id, 1);

    if (cur != 1 && g[cur].size() == 1)
    {
        if (h & 1)
        {
            int idx = bs(s, h / 2 + 1);
            dp[cur] = seq[idx];
        }
        else
        {
            int idx1 = bs(s, h / 2), idx2 = bs(s, h / 2 + 1);
            dp[cur] = (seq[idx1] + seq[idx2]) / 2;
        }
        s.pupd(id, id, -1);
        return dp[cur];
    }
    dp[cur] = inf;
    if (h & 1)
        dp[cur] = 0;
    for (int e : g[cur])
    {
        if (e != last)
        {
            if (h & 1)
                dp[cur] = max(dp[cur], dfs(s, e, cur, h + 1));
            else
                dp[cur] = min(dp[cur], dfs(s, e, cur, h + 1));
        }
    }
    s.pupd(id, id, -1);
    return dp[cur];
}

int solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        seq.pb(arr[i]);
    }
    sort(seq.begin(), seq.end());
    seq.resize(unique(seq.begin(), seq.end()) - seq.begin());
    int sz = seq.size();
    segtree<node> s(sz);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int ans = dfs(s, 1, 1, 1);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}