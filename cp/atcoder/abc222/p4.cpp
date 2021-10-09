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

const int MOD = 998244353, N = 3005;

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

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(N));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int pre = 0;
        for (int j = 0; j < N; j++)
        {
            pre = add(pre, dp[i - 1][j]);
            if (j >= a[i] && j <= b[i])
                dp[i][j] = pre;
        }
    }
    for (int i = a[n]; i <= b[n]; i++)
        res = add(res, dp[n][i]);
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