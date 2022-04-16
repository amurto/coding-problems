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

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    x %= MOD;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int solve()
{
    int n, m, k, res = 0;
    cin >> n >> m >> k;
    vector<int> dp(k + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        vector<int> tdp(k + 1);
        for (int j = 1; j <= m; j++)
            for (int t = 0; t <= k - j; t++)
                tdp[t + j] = add(tdp[t + j], dp[t]);
        swap(dp, tdp);
    }
    for (int i = 1; i <= k; i++)
        res = add(res, dp[i]);
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