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

const int MOD = 998244353, N = 305;

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

void solve()
{
    int n, k, h = power(2, MOD - 2, MOD);
    cin >> n >> k;
    vector<int> arr(n), dp(k + 1), st(k + 1);
    vector<vector<int>> pw(n, vector<int>(k + 1));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pw[i][0] = 1;
        for (int j = 1; j <= k; j++)
            pw[i][j] = mul(pw[i][j - 1], arr[i]);
    }
    for (int j = 0; j <= k; j++)
    {
        for (int i = 0; i < n; i++)
            st[j] = add(st[j], pw[i][j]);
        st[j] = mul(st[j], invfact[j]);
    }
    for (int j = 1; j <= k; j++)
    {
        for (int i = 0; i <= j; i++)
            dp[j] = add(dp[j], mul(st[i], st[j - i]));
        dp[j] = mul(dp[j], fact[j]);
    }
    for (int i = 0; i < n; i++)
        for (int j = 1, cur = 2 * arr[i]; j <= k; j++, cur = mul(cur, 2 * arr[i]))
            dp[j] = add(dp[j], -cur);
    for (int i = 1; i <= k; i++)
    {
        dp[i] = mul(dp[i], h);
        cout << dp[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}