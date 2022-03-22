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

const int MOD = 998244353, N = 255;

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
int fact[N], invfact[N], pw[N][N], inv_val[N];
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
    for (int j = 1; j < N; j++)
    {
        pw[j][0] = 1;
        for (int k = 1; k < N; k++)
            pw[j][k] = mul(pw[j][k - 1], j);
    }
    inv_val[1] = 1;
    for (int j = 2; j < N; j++)
        inv_val[j] = power(j, MOD - 2, MOD);
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
    int n, k, res = 0;
    cin >> n >> k;
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    for (int i = 1; i <= k; i++)
        dp[i][1] = 1;
    for (int i = 1; i < n - 1; i++)
    {
        vector<vector<int>> tdp(k + 1, vector<int>(n + 1));
        for (int wt = 1; wt <= k; wt++)
        {
            for (int rep = 1; rep <= i; rep++)
            {
                if (dp[wt][rep] > 0)
                {
                    for (int nwt = wt; nwt <= k; nwt++)
                    {
                        if (wt == nwt)
                            tdp[nwt][rep + 1] = add(tdp[nwt][rep + 1], mul(dp[wt][rep], mul(pw[k - nwt + 1][i], inv_val[rep + 1])));
                        else
                            tdp[nwt][1] = add(tdp[nwt][1], mul(dp[wt][rep], pw[k - nwt + 1][i]));
                    }
                }
            }
        }
        swap(dp, tdp);
    }
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n - 1; j++)
            res = add(res, dp[i][j]);
    res = mul(res, fact[n - 1]);
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