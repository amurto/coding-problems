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

const int N = 2e5 + 5;
vector<int> g[N];
ll dp[N], sz[N], res[N];

void precompute(int cur, int last)
{
    dp[cur] = 0;
    sz[cur] = 1;
    for (int e : g[cur])
    {
        if (e != last)
        {
            precompute(e, cur);
            sz[cur] += sz[e];
            dp[cur] += dp[e] + sz[e];
        }
    }
}

void dfs(int cur, int last, ll sum, int n)
{
    res[cur] = dp[cur] + sum;
    for (int e : g[cur])
        if (e != last)
            dfs(e, cur, res[cur] - dp[e] - sz[e] + n - sz[e], n);
}

void solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    precompute(1, 1);
    dfs(1, 1, 0, n);
    for (int i = 1; i <= n; i++)
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