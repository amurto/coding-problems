#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 105;
int dp[N][N][N];

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

int inv(int x)
{
    return power(x, MOD - 2, MOD);
}

int dfs(int r, int a, int b)
{
    if (dp[r][a][b] == -1)
    {
        if (b == 0)
            dp[r][a][b] = add(1, dfs(a, 0, a));
        else
        {
            int d = r - a - b, den = inv(r - 1), p = 0;
            // choose from a
            if (a > 0)
                p = add(p, mul(mul(a, den), dfs(r, a, b - 1)));
            // choose from b
            if (b > 1)
                p = add(p, mul(mul(b - 1, den), dfs(r, a + 1, b - 2)));
            // choose from d
            if (d > 0)
                p = add(p, mul(mul(d, den), dfs(r, a + 1, b - 1)));
            dp[r][a][b] = p;
        }
    }
    return dp[r][a][b];
}

void init()
{
    memset(dp, -1, sizeof(dp));
    dp[1][0][1] = 0;
    dp[2][0][2] = 1;
    dfs(N - 1, 0, N - 1);
}

int solve()
{
    int n;
    cin >> n;
    return dp[n][0][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}