#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 205, LGN = 9;
vector<int> g[N];
int dp[N][N], dis[N][N], up[N][LGN + 1], tin[N], tout[N], dep[N], timer = 0;

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

void dfs(int cur, int last, int d)
{
    tin[cur] = ++timer;
    dep[cur] = d;
    up[cur][0] = last;
    for (int i = 1; i <= LGN; i++)
        up[cur][i] = up[up[cur][i - 1]][i - 1];
    for (int e : g[cur])
        if (e != last)
            dfs(e, cur, d + 1);
    tout[cur] = timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LGN; i >= 0; i--)
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

void compute_dis(int rt, int cur, int last, int d)
{
    dis[rt][cur] = dis[cur][rt] = d;
    for (int e : g[cur])
        if (e != last)
            compute_dis(rt, e, cur, d + 1);
}

int sub(vector<bool> &vis, int cur, int last)
{
    int sum = 1;
    for (int e : g[cur])
        if (!vis[e] && e != last)
            sum += sub(vis, e, cur);
    return sum;
}

int solve()
{
    int n, u, v, res = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 1;
    }
    int h = power(2, MOD - 2, MOD), den = power(n, MOD - 2, MOD);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = mul(h, add(dp[i - 1][j], dp[i][j - 1]));
    for (int i = 1; i <= n; i++)
        compute_dis(i, i, i, 0);
    dfs(1, 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            vector<bool> vis(n + 1);
            vector<int> seq, tmp;
            int l = lca(i, j), cur = i;
            while (cur != l)
            {
                seq.pb(cur);
                vis[cur] = true;
                cur = up[cur][0];
            }
            seq.pb(cur);
            cur = j;
            while (cur != l)
            {
                seq.pb(cur);
                vis[cur] = true;
                cur = up[cur][0];
            }
            cout << i << " " << j << " -> ";
            for (int e : seq)
                cout << e << " ";
            cout << "\n";
            for (int e : seq)
                res = add(res, mul(den, mul(sub(vis, e, e), dp[dis[i][e]][dis[j][e]])));
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}