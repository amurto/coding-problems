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

const int MOD = 998244353, N = 805;

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

int combine(int x, int y)
{
    return mul(fact[x + y], mul(invfact[x], invfact[y]));
}

int solve()
{
    int n, m, a, b;
    cin >> n >> m;
    n *= 2;
    vector<vector<int>> g(n, vector<int>(n)), dp(n, vector<int>(n)), tdp(n, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a][b] = g[b][a] = 1;
    }
    for (int i = 0; i < n - 1; i++)
        tdp[i][i + 1] = dp[i][i + 1] = g[i][i + 1];
    for (int gap = 4; gap <= n; gap++)
    {
        for (int i = 0, j = gap - 1; j < n; i++, j++)
        {
            if (g[i][j])
                tdp[i][j] = dp[i + 1][j - 1];
            for (int k = i + 1; k < j - 1; k++)
                dp[i][j] = add(dp[i][j], mul(tdp[i][k], mul(dp[k + 1][j], combine((k - i + 1) / 2, (j - k) / 2))));
            dp[i][j] = add(dp[i][j], tdp[i][j]);
        }
    }
    return dp[0][n - 1];
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