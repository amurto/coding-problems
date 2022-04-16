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

int add(int x, int y, int MOD)
{
    x += y;
    x %= MOD;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y, int MOD)
{
    return (x * 1ll * y) % MOD;
}

void solve()
{
    int n, MOD;
    cin >> n >> MOD;
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][1] = dp[1][0] = 1;
    for (int i = 1; i < n; i++)
    {
        vector<vector<int>> tdp(2, vector<int>(n));
        for (int rem = 0; rem < n; rem++)
        {
            // dp[0][rem]
            tdp[1][rem] = add(tdp[1][rem], dp[0][rem], MOD);
            if (rem + 1 < n)
                tdp[0][rem + 1] = add(tdp[0][rem + 1], dp[0][rem], MOD);

            // dp[1][rem]
            tdp[1][rem] = add(tdp[1][rem], dp[1][rem], MOD);
            if (rem + 1 < n)
                tdp[1][rem + 1] = add(tdp[1][rem + 1], mul(3, dp[1][rem], MOD), MOD);
            if (rem + 2 < n)
                tdp[0][rem + 2] = add(tdp[0][rem + 2], mul(2, dp[1][rem], MOD), MOD);
        }
        swap(dp, tdp);
    }
    for (int i = 1; i < n; i++)
        cout << dp[1][i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}