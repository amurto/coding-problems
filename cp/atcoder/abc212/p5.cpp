#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int solve()
{
    int n, m, k, u, v;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        g[i].pb(i);
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    dp[0][1] = 1;
    int sum = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = sum;
            for (int e : g[j])
                dp[i][j] = add(dp[i][j], -dp[i - 1][e]);
        }
        sum = 0;
        for (int j = 1; j <= n; j++)
            sum = add(sum, dp[i][j]);
    }
    return dp[k][1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}