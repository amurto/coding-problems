#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353, K = 11;

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
    int n, st = 1 << (K - 1);
    string str;
    cin >> n >> str;
    str = "K" + str;
    vector<vector<int>> dp(1 << K, vector<int>(K));
    dp[st][K - 1] = 1;
    for (int i = 1; i <= n; i++)
    {
        int cur = str[i] - 'A';
        vector<vector<int>> tdp = dp;
        for (int b = st; b < (1 << K); b++)
        {
            for (int j = 0; j < K; j++)
            {
                if ((b >> j) & 1)
                {
                    if (j == cur)
                        tdp[b][j] = add(tdp[b][j], dp[b][j]);
                    else if (!((b >> cur) & 1))
                        tdp[b | (1 << cur)][cur] = add(tdp[b | (1 << cur)][cur], dp[b][j]);
                }
            }
        }
        swap(dp, tdp);
    }
    int res = -1;
    for (int b = st; b < (1 << K); b++)
        for (int j = 0; j < K; j++)
            if ((b >> j) & 1)
                res = add(res, dp[b][j]);
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