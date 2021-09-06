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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    arr.pb(0);
    for (int i = 1; i <= m; i++)
    {
        int cnt = 0;
        for (int j = i; j <= n; j += m)
            cnt++;
        arr.pb(cnt);
    }
    int sz = arr.size();
    vector<vector<int>> dp(sz, vector<int>(n + 1));
    // k buckets
    // choose j buckets and create arr[i]-j new buckets
    dp[0][0] = 1;
    for (int i = 1; i < sz; i++)
        for (int k = 0; k <= n; k++)
            if (dp[i - 1][k] > 0)
                for (int j = 0; j <= min(arr[i], k); j++)
                    dp[i][k + arr[i] - j] = add(dp[i][k + arr[i] - j], mul(dp[i - 1][k], mul(fact[j], mul(ncr(arr[i], j), ncr(k, j)))));
    for (int i = 1; i <= n; i++)
        cout << dp[sz - 1][i] << "\n";
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