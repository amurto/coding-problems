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

int dfs(vector<int> &dp, int cur, int k)
{
    if (cur == k - 1)
        return 4;
    if (dp[cur] == -1)
        dp[cur] = (cur == 0) ? mul(6, mul(dfs(dp, cur + 1, k), dfs(dp, cur + 1, k))) : mul(4, mul(dfs(dp, cur + 1, k), dfs(dp, cur + 1, k)));
    return dp[cur];
}

int solve()
{
    int k;
    cin >> k;
    if (k == 1)
        return 6;
    vector<int> dp(k, -1);
    return dfs(dp, 0, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}