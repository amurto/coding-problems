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

const int MOD = 998244353, N = 1005, M = 12;
int dp[N][M][M][M];

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

int calc(int cur, int a, int b, int c, int n, int m)
{
    if (cur == n)
        return c <= m;
    if (dp[cur][a][b][c] == -1)
    {
        int res = 0;
        for (int t = 1; t <= min(c, m); t++)
        {
            int ta = a, tb = b, tc = c;
            ta = min(a, t);
            if (t > a)
                tb = min(b, t);
            if (t > b)
                tc = min(c, t);
            res = add(res, calc(cur + 1, ta, tb, tc, n, m));
        }
        dp[cur][a][b][c] = res;
    }
    return dp[cur][a][b][c];
}

int solve()
{
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    int res = calc(0, M - 1, M - 1, M - 1, n, m);
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