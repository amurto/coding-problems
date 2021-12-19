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

const int MOD = 998244353, N = 1e6 + 5;

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

// factorial and inverse factorial
int fact[N], invfact[N];
void init()
{
    fact[0] = fact[1] = 1;
    int i;
    for (i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
    i--;
    // Fermat's Little Theorem
    // 1/(a! % mod) = a!^mod-2 % mod
    invfact[i] = power(fact[i], MOD - 2, MOD);
    for (i--; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * 1ll * (i + 1)) % MOD;
}

// NCR
// n!/r!*(n-r)!
int ncr(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return mul(fact[n], mul(invfact[r], invfact[n - r]));
}

vector<vector<int>> calc(int n, int k)
{
    vector<vector<int>> dp(k + 1, vector<int>(2));
    // dp[i][0] -> reach start
    // dp[i][1] -> reach other point
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++)
    {
        dp[i][0] = mul(dp[i - 1][1], n - 1);
        if (n > 2)
            dp[i][1] = mul(dp[i - 1][1], n - 2);
        dp[i][1] = add(dp[i][1], dp[i - 1][0]);
    }
    return dp;
}

int solve()
{
    int h, w, k, x1, y1, x2, y2, res = 0;
    cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;
    vector<vector<int>> dpx = calc(h, k), dpy = calc(w, k);
    int tx = 0, ty = 0;
    if (x1 != x2)
        tx = 1;
    if (y1 != y2)
        ty = 1;
    for (int i = 0; i <= k; i++)
    {
        int j = k - i;
        res = add(res, mul(mul(fact[k], mul(invfact[i], invfact[j])), mul(dpx[i][tx], dpy[j][ty])));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << solve() << "\n";
    return 0;
}