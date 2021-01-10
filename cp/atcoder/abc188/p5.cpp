#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll N = 2e5 + 1, inf = 1e9;
vector<vector<int>> g(N);
vector<ll> C(N), dp(N);
vector<bool> vis(N);
ll res = -inf;

ll dfs(int cur)
{
    if (vis[cur])
        return dp[cur];
    dp[cur] = -inf;
    vis[cur] = true;
    for (int e : g[cur])
        dp[cur] = max(dp[cur], dfs(e));
    res = max(res, dp[cur] - C[cur]);
    dp[cur] = max(C[cur], dp[cur]);
    return dp[cur];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> C[i];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
    }
    for (int i = 1; i <= n; i++)
        dfs(i);
    cout << res << "\n";
    return 0;
}