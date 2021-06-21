#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MOD = 1e9 + 7, N = 105;
int dp[N][N][N];
int vis[N][N][N];

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

int inv(int x)
{
    return power(x, MOD - 2, MOD);
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
int dfs(int e, int rem, int cur)
{
    if (e == 0 && rem == 1)
        return 1;
    if (cur == 0)
        return dfs(0, rem, rem);
    if (vis[e][rem][cur] == -1)
    {
        int sum = e + rem - 1;
        int res = 1;
        // cur is already eliminated
        if (e > 0)
            res = mul(res, dfs(e, rem, cur - 1));
        // eliminate someone
        if (rem > 1)
            res = mul(res, mul(mul(rem - 1, inv(sum)), dfs(e + 1, rem - 1, cur - 1)));
        // choose from rem

        dp[e][rem][cur] = res;
    }
    return dp[e][rem][cur];
}

int solve()
{
    int n;
    cin >> n;
    memset(vis, -1, sizeof(dp));
    int res = dfs(0, n, n);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}