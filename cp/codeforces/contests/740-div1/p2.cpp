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

int MOD;

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

int solve()
{
    int n;
    cin >> n >> MOD;
    int mx = n + 1;
    vector<int> dp(mx + 1), pdp(mx + 1);
    dp[n] = 1;
    pdp[n] = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        dp[i] = pdp[i + 1];
        int cur = 2;
        for (int j = cur * i; j <= n; j += i, cur++)
            dp[i] = add(dp[i], add(pdp[j], -pdp[min(mx, j + cur)]));
        pdp[i] = add(pdp[i + 1], dp[i]);
    }
    return dp[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}