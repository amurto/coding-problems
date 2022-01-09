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

const int MOD = 998244353, N = 5005;

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

int solve()
{
    string str;
    cin >> str;
    int n = (int)str.length(), res = 0;
    vector<int> dp(n + 1), cnt(26);
    for (char ch : str)
        cnt[ch - 'a']++;
    dp[0] = 1;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] > 0)
        {
            vector<int> tdp = dp;
            for (int j = 1; j <= cnt[i]; j++)
                for (int k = 0; k <= n; k++)
                    if (dp[k] > 0)
                        tdp[j + k] = add(tdp[j + k], mul(dp[k], invfact[j]));
            swap(dp, tdp);
        }
    }
    for (int i = 1; i <= n; i++)
        res = add(res, mul(fact[i], dp[i]));
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