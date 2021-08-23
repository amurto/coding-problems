// https://codeforces.com/contest/1027/problem/E
// Inverse Coloring

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

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

int solve()
{
    int n, k, res = 0;
    cin >> n >> k;
    vector<int> tdp(n + 1), pdp(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[0][0] = dp[0][1] = 1;
    for (int seg = 1; seg <= n; seg++)
    {
        for (int i = 1; i <= n; i++)
            for (int p = 0; p < 2; p++)
                dp[i][p] = 0;
        for (int i = 1; i <= n; i++)
            for (int p = 0; p < 2; p++)
                for (int j = i - 1; j >= max(0, i - seg); j--)
                    dp[i][p] = add(dp[i][p], dp[j][p ^ 1]);
        tdp[seg] = add(add(dp[n][0], dp[n][1]), -pdp[seg - 1]);
        pdp[seg] = pdp[seg - 1];
        pdp[seg] = add(pdp[seg], tdp[seg]);
    }
    for (int seg = 1; seg <= n; seg++)
        res = add(res, mul(tdp[seg], pdp[min(n, ((k + seg - 1) / seg) - 1)]));
    return mul(res, power(2, MOD - 2, MOD));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}