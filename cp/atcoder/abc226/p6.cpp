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

const int MOD = 998244353, N = 55, M = 4e5 + 5;
int id[M];
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
int power(int n, int m, int p = MOD)
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
    if (r == 1)
        return 1;
    return mul(fact[r - 1], mul(fact[n], mul(invfact[r], invfact[n - r])));
}

int lcm(int x, int y)
{
    x /= __gcd(x, y);
    return x * y;
}

void dfs(vector<int> &st, int l, int mx, int sum, int n)
{
    if (sum == n)
    {
        st.pb(l);
        return;
    }
    for (int i = mx; i <= n - sum; i++)
        dfs(st, lcm(l, i), i, sum + i, n);
}

int solve()
{
    int n, K, res = 0;
    cin >> n >> K;
    vector<int> st;
    dfs(st, 1, 1, 0, n);
    sort(st.begin(), st.end());
    st.resize(unique(st.begin(), st.end()) - st.begin());
    int sz = (int)st.size();
    for (int i = 0; i < sz; i++)
        id[st[i]] = i;
    vector<vector<int>> divs(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            divs[j].pb(i);
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(sz, vector<int>(n + 1)));
    dp[0][0][0] = fact[n];
    // dp[i][j][k] -> dp(sum, lcm, max)
    for (int i = 1; i <= n; i++)
    {
        for (int p = 0; p < i; p++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < i; k++)
                {
                    if (dp[p][j][k] > 0)
                    {
                        int e = i - p;
                        for (int dv : divs[e])
                        {
                            if (dv > k)
                            {
                                int t = id[lcm(st[j], dv)], r = e / dv;
                                dp[i][t][dv] = add(dp[i][t][dv], mul(mul(invfact[r], mul(power(fact[dv - 1], r), power(invfact[dv], r))), dp[p][j][k]));
                            }
                        }
                    }
                }
            }
        }
    }
    vector<int> arr(sz);
    for (int j = 0; j < sz; j++)
        for (int k = 1; k <= n; k++)
            if (dp[n][j][k] > 0)
                arr[j] = add(arr[j], dp[n][j][k]);
    for (int i = 0; i < sz; i++)
        res = add(res, mul(power(st[i], K, MOD), arr[i]));
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