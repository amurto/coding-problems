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

const ll inf = 1e18;
ll solve()
{
    int n;
    ll dd, res = inf;
    cin >> n >> dd;
    vector<vector<ll>> adj(n, vector<ll>(n)), dp(n, vector<ll>(n, inf));
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cin >> adj[i][j];
            adj[i][j] += dd * 1ll * (j - i);
            adj[j][i] = adj[i][j];
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i < n; i++)
    {
        // dp[i-1][j]
        for (int j = 0; j < i; j++)
        {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + adj[i - 1][i]);
            dp[i - 1][i] = min(dp[i - 1][i], dp[i - 1][j] + adj[j][i]);
        }
        // dp[j][i-1]
        for (int j = 0; j < i; j++)
        {
            dp[j][i] = min(dp[j][i], dp[j][i - 1] + adj[i - 1][i]);
            dp[i][i - 1] = min(dp[i][i - 1], dp[j][i - 1] + adj[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
        res = min(res, min(dp[i][n - 1] + adj[i][n - 1], dp[n - 1][i] + adj[i][n - 1]));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}