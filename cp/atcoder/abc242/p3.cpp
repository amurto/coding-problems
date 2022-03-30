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

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int solve()
{
    int n;
    cin >> n;
    vector<int> dp(10, 1);
    for (int i = 2; i <= n; i++)
    {
        vector<int> tdp(10);
        for (int j = 1; j <= 9; j++)
            for (int k = j - 1; k <= j + 1; k++)
                if (k >= 1 && k <= 9)
                    tdp[j] = add(tdp[j], dp[k]);
        swap(dp, tdp);
    }
    int res = 0;
    for (int i = 1; i <= 9; i++)
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