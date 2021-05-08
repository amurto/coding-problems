#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 5e5 + 5;
// Entry and Exit time for Segment Tree
vector<int> g[N], vis1(N), vis2(N), dep(N);

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

// factorial and inverse factorial
int fact[N], invfact[N], odd[N], even[N];

// NCR
// n!/r!*(n-r)!
int ncr(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return mul(fact[n], mul(invfact[r], invfact[n - r]));
}

void init()
{
    fact[0] = fact[1] = 1;
    int i;
    for (i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
    i--;
    // Fermat's Little Theorem
    // 1/(a! % mod) = a!^mod-2 % mod
    invfact[i] = power(fact[i], MOD - 2, MOD);
    for (i--; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * 1ll * (i + 1)) % MOD;
    odd[0] = even[0] = 0;
    for (int i = 1; i < N; i++)
    {
        even[i] = add(even[i - 1], odd[i - 1]);
        odd[i] = add(even[i], 1);
    }
}

int dfs(int cur, int last, int t, int lvl)
{
    vis1[cur] = vis2[cur] = t;
    dep[cur] = lvl;
    if (g[cur].size() == 1 && g[cur][0] == last)
        return vis1[cur];
    int mx = vis1[cur];
    for (int e : g[cur])
        if (e != last)
            vis2[cur] = dfs(e, cur, vis2[cur] + 1, lvl + 1);
    return vis2[cur];
}

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

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v] = arr[tl];
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

void solve()
{
    int n, u, v, q, t, x;
    cin >> n;
    vector<int> nodes(n), arr(n + 1);
    iota(nodes.begin(), nodes.end(), 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] %= 2;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 1, 0, 0);
    sort(nodes.begin(), nodes.end(), [&](int &i1, int &i2) {
        return vis1[i1] < vis2[i2];
    });
    vector<int> seq(n);
    for (int i = 0; i < n; i++)
        seq[i] = arr[nodes[i]] > 1;
    segtree<node> s(n);
    s.build(seq);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> v >> x;
            s.rupd(vis1[v], vis1[v], (x > 1));
        }
        else
        {
            cin >> v;
            int subtree = vis2[v] - vis1[v] + 1;
            int sum = s.query(vis1[v], vis2[v]).v;
            int two = power(2, subtree - sum, MOD);
            int res = add(mul(even[sum], two), sum - subtree);
            cout << even[sum] << "\n";
            cout << res << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}