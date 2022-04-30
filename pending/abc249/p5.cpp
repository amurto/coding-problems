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

const int K = 26;
int add(int x, int y, int MOD)
{
    x += y;
    x %= MOD;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y, int MOD)
{
    return (x * 1ll * y) % MOD;
}

int solve()
{
    int n, MOD, res = 0;
    cin >> n >> MOD;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1)), pre(n + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j - 1 >= 0)
                pre[i][j] = add(pre[i][j], pre[i][j - 1], MOD);
            dp[i][j] = add(dp[i][j], pre[i][j], MOD);
            int m = 26;
            if (j > 0)
                m = 25;
            int val = mul(m, dp[i][j], MOD);
            if (val > 0)
            {
                for (int t = 2, l = 1, r = 9; r <= n; t++)
                {
                    if (i + t <= n)
                    {
                        int mn = min(n + 1, j + l), mx = min(n, j + r);
                        if (mn <= n)
                        {
                            pre[i + t][mn] = add(pre[i + t][mn], val, MOD);
                            if (mx + 1 <= n)
                                pre[i + t][mx + 1] = add(pre[i + t][mx + 1], -val, MOD);
                        }
                    }
                    l *= 10;
                    r = l * 10 - 1;
                }
            }
            if (i + j > 0 && i < j)
                res = add(res, dp[i][j], MOD);
        }
    }
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