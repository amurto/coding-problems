// https://codeforces.com/contest/908/problem/D
// New Year and Arbitrary Arrangement

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

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

int dfs(vector<vector<int>> &dp, int p, int q, int a, int ab, int k, int c)
{
    if (ab >= k)
        return ab;
    if (a + ab >= k)
        return add(add(ab, a), c);
    if (dp[a][ab] == -1)
        dp[a][ab] = add(mul(p, dfs(dp, p, q, a + 1, ab, k, c)), mul(q, dfs(dp, p, q, a, ab + a, k, c)));
    return dp[a][ab];
}
int solve()
{
    int k, pA, pB;
    cin >> k >> pA >> pB;
    int p = mul(pA, power(pA + pB, MOD - 2, MOD));
    int q = mul(pB, power(pA + pB, MOD - 2, MOD));
    int c = mul(p, power(q, MOD - 2, MOD));
    vector<vector<int>> dp(k + 1, vector<int>(k + 1, -1));
    return dfs(dp, p, q, 1, 0, k, c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}