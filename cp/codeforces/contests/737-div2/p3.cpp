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

const int MOD = 1e9 + 7, N = 3e5 + 1;

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
    vector<int> dp(k + 1);
    int c = power(2, n - 1, MOD);
    dp[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        int rem = k - i;
        int p = power(power(2, rem, MOD), n, MOD);
        if (n % 2 == 0)
            dp[i] = mul(dp[i - 1], add(c, -1));
        else
            dp[i] = mul(dp[i - 1], c);
        if (n % 2 == 0)
            res = add(res, mul(dp[i - 1], p));
        if (n % 2 == 1)
            dp[i] = add(dp[i], dp[i - 1]);
    }
    res = add(res, dp[k]);
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