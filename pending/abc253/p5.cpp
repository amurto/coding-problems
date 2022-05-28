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
    x %= MOD;
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
    int n, m, k, res = 0;
    cin >> n >> m >> k;
    if (k == 0)
        return power(m, n, MOD);
    vector<int> dp(m + 1, 1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        vector<int> tdp(m + 1);
        int prev = 0;
        for (int l = 1, r = 1 + k; r <= m; l++, r++)
        {
            prev = add(prev, dp[l]);
            tdp[r] = add(tdp[r], prev);
        }
        prev = 0;
        for (int l = m, r = m - k; r > 0; l--, r--)
        {
            prev = add(prev, dp[l]);
            tdp[r] = add(tdp[r], prev);
        }
        swap(dp, tdp);
    }
    for (int i = 1; i <= m; i++)
        res = add(res, dp[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}