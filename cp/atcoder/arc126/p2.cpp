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

int solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> g(2, vector<vector<int>>(n + 1));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[0][a].pb(b);
        g[1][b].pb(a);
    }
    vector<vector<int>> dp(3, vector<int>(n + 2));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
            dp[j][i] = max(dp[j][i], max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1])));
        for (int j = 0; j < 2; j++)
            dp[j][i] = max(dp[j][i], dp[2][i]);
        for (int j = 0; j < 2; j++)
            for (int x : g[j][i])
                if (x >= i)
                    if (x == i)
                        dp[2][i + 1] = dp[2][i] + 1;
                    else
                        dp[j][x] = dp[j][i] + 1;
    }
    dp[2][n + 1] = max(dp[2][n + 1], max(dp[0][n], dp[1][n]));
    return dp[2][n + 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}