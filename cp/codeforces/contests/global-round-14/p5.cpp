#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 405;
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
int two[N], fact[N], invfact[N];
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
    two[0] = 1;
    for (int i = 1; i < N; i++)
        two[i] = mul(two[i - 1], 2);
}

int solve()
{
    int n, res = 0;
    cin >> n >> MOD;
    init();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        dp[i][i] = mul(two[i - 1], invfact[i]);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i - 1; j++)
        {
            int mov = i - j - 1, d = mul(two[i - j - 2], invfact[i - j - 1]);
            for (int k = 1; k <= j; k++)
                dp[i][k + mov] = add(dp[i][k + mov], mul(dp[j][k], d));
        }
    }
    for (int i = 1; i <= n; i++)
        res = add(res, mul(fact[i], dp[n][i]));
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