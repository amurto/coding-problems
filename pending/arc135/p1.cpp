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

const int MOD = 998244353;

map<ll, int> dp;

int add(int x, int y)
{
    x += y;
    // x %= MOD;
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

int calc(ll n)
{
    if (n <= 3)
        return n;
    if (dp[n] == 0)
        dp[n] = mul(calc(n / 2), calc((n + 1) / 2));
    return dp[n];
}
int solve()
{
    ll n;
    cin >> n;
    return calc(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}