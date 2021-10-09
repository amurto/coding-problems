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

const int MOD = 998244353, N = 1005, S = 2e5 + 10;
vector<int> g[N];
int dp[N][S];
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

int tin[N], tout[N], dep[N], timer = 0;

void dfs(int cur, int last, int dd)
{
    tin[cur] = ++timer;
    dep[cur] = dd;
    for (int e : g[cur])
        if (e != last)
            dfs(e, cur, dd + 1);
    tout[cur] = timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int calc(vector<int> &cnt, int cur, int sum, int k, int sz)
{
    if (cur == sz)
        return sum == k;
    if (dp[cur][sum] == -1)
        dp[cur][sum] = add(calc(cnt, cur + 1, sum + cnt[cur], k, sz), calc(cnt, cur + 1, sum - cnt[cur], k, sz));
    return dp[cur][sum];
}

int solve()
{
    int n, m, k, res = 0;
    cin >> n >> m >> k;
    vector<int> a(m), u(n - 1), v(n - 1), cnt(n - 1);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u[i] >> v[i];
        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
    }
    dfs(1, 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        if (dep[u[i]] > dep[v[i]])
            swap(u[i], v[i]);
        for (int j = 1; j < m; j++)
        {
            if (is_ancestor(v[i], a[j - 1]) && !is_ancestor(v[i], a[j]))
                cnt[i]++;
            else if (is_ancestor(v[i], a[j]) && !is_ancestor(v[i], a[j - 1]))
                cnt[i]++;
        }
    }
    memset(dp, -1, sizeof(dp));
    int st = 1e5 + 5;
    res = calc(cnt, 0, st, st + k, n - 1);
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