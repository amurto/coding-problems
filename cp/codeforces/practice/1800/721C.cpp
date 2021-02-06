// https://codeforces.com/contest/721/problem/C
// Journey

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e10;

void traverse(vector<vector<ll>> &dp, vector<int> &vis, vector<vector<pair<int, ll>>> &g, int cur, int e)
{
    vis.pb(cur);
    if (e <= 1)
        return;
    for (pair<int, int> v : g[cur])
    {
        if (dp[cur][e] < inf && dp[cur][e] == v.second + dp[v.first][e - 1])
        {
            traverse(dp, vis, g, v.first, e - 1);
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, t, u, v;
    ll c;
    cin >> n >> m >> t;
    vector<vector<pair<int, ll>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        g[v].pb({u, c});
    }
    vector<vector<ll>> dp(n + 2, vector<ll>(n + 2, inf));
    dp[1][1] = 0;
    for (int e = 1; e <= n; e++)
        for (int i = 2; i <= n; i++)
            for (pair<int, ll> v : g[i])
                dp[i][e] = min(dp[i][e], v.second + dp[v.first][e - 1]);
    int k = 0;
    for (int i = 2; i <= n; i++)
        if (dp[n][i] <= t)
            k = i;
    cout << k << "\n";
    vector<int> vis;
    traverse(dp, vis, g, n, k);
    reverse(vis.begin(), vis.end());
    for (int v : vis)
        cout << v << " ";
    return 0;
}