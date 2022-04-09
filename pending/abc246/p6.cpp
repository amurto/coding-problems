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

const int MOD = 998244353, N = 55, K = 26;

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
    int n, l, res = 0;
    cin >> n >> l;
    vector<string> str(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        for (char ch : str[i])
            arr[i] |= (1 << (ch - 'a'));
    }
    vector<int> pw(K + 1), dp(K + 1), cnt(K + 1);
    for (int i = 1; i <= K; i++)
    {
        pw[i] = power(i, l, MOD);
        for (int j = i, t = 0; j > 0; j--, t ^= 1)
        {
            if (t == 0)
                dp[i] = add(dp[i], mul(ncr(i, j), pw[j]));
            else
                dp[i] = add(dp[i], -mul(ncr(i, j), pw[j]));
        }
    }
    vector<bool> vis(1 << K);
    for (int i = 0; i < n; i++)
    {
        bool pos = false;
        for (int j = 0; j < i; j++)
            if ((arr[j] | arr[i]) == arr[j])
                pos = true;
        if (!pos)
        {
            for (int j = arr[i]; j >= 0; j = (j - 1) & arr[i])
            {
                vis[j] = true;
                // mask is original set
                // j is subset
                if (j == 0)
                    break;
            }
        }
    }
    for (int j = 1; j < (1 << K); j++)
        if (vis[j])
            cnt[__builtin_popcount(j)]++;
    for (int i = 1; i <= K; i++)
        res = add(res, mul(cnt[i], dp[i]));
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