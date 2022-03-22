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
typedef pair<int, pair<int, int>> piii;
#define pb push_back

const int MOD = 998244353, N = 2e5 + 5;

int add(int x, int y)
{
    x += y;
    x %= MOD;
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

int inv(int x)
{
    return power(x, MOD - 2, MOD);
}

// factorial and inverse factorial
int fact[N], invfact[N], inv_val[N];
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
    inv_val[1] = 1;
    for (int j = 2; j < N; j++)
        inv_val[j] = inv(j);
}

// NCR
// n!/r!*(n-r)!
int ncr(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return mul(fact[n], mul(invfact[r], invfact[n - r]));
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n + 1, 1), lcm(n + 1, 1), dp(n + 1, 1), nodes;
    vector<vector<piii>> g(n + 1);
    vector<bool> vis(n + 1);
    for (int e = 0; e < n - 1; e++)
    {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        g[i].pb({j, {x, y}});
        g[j].pb({i, {y, x}});
    }
    for (int i = 1; i <= n; i++)
    {
        int g_val = 0;
        lcm[i] = 1;
        for (piii e : g[i])
        {
            lcm[i] = mul(lcm[i], e.second.first);
            g_val = __gcd(g_val, e.second.first);
        }
        if ((int)g[i].size() > 1)
            lcm[i] = mul(lcm[i], inv_val[g_val]);
    }

    // Lambda recursive function
    auto dfs1 = [&](const auto &self, int cur) -> void
    {
        vis[cur] = true;
        nodes.pb(cur);
        for (piii e : g[cur])
            if (!vis[e.first])
                self(self, e.first);
    };

    auto dfs2 = [&](const auto &self, int cur) -> int
    {
        vis[cur] = true;
        for (piii e : g[cur])
            if (!vis[e.first])
                dp[cur] = mul(mul(dp[cur], inv_val[e.second.second]), self(self, e.first));
        return dp[cur];
    };

    auto dfs3 = [&](const auto &self, int cur, int val) -> void
    {
        vis[cur] = true;
        arr[cur] = mul(arr[cur], mul(val, dp[cur]));
        for (piii e : g[cur])
            if (!vis[e.first])
                self(self, e.first, mul(val, mul(dp[cur], inv(dp[e.first]))));
    };
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            nodes.clear();
            dfs1(dfs1, i);
            int lcm_val = 1, dv = 1;
            for (int node : nodes)
                lcm_val = mul(lcm_val, lcm[node]);
            for (int node : nodes)
            {
                arr[node] = lcm_val;
                vis[node] = false;
            }
            dfs2(dfs2, i);
            for (int node : nodes)
                vis[node] = false;
            dfs3(dfs3, i, 1);
        }
    }
    for (int i = 1; i <= n; i++)
        res = add(res, arr[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}