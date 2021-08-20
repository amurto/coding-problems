// https://codeforces.com/contest/466/problem/D
// Increase Sequence

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

const int MOD = 1e9 + 7, N = 3e5 + 1;

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
    int n, h;
    cin >> n >> h;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int mx = *max_element(arr.begin(), arr.end());
    if (mx > h)
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int req = h - arr[i];
        for (int j = max(0, req - 1); j <= req; j++)
        {
            // do nothing
            if (j == req)
                dp[i][j] = add(dp[i][j], dp[i - 1][j]);
            // add 1
            if (j + 1 <= n && j + 1 == req)
                dp[i][j + 1] = add(dp[i][j + 1], dp[i - 1][j]);
            // add 1 remove 1
            if (j + 1 <= n && j + 1 == req)
                dp[i][j] = add(dp[i][j], mul(j + 1, dp[i - 1][j]));
            // remove 1
            if (j - 1 >= 0 && j == req)
                dp[i][j - 1] = add(dp[i][j - 1], mul(j, dp[i - 1][j]));
        }
    }
    return dp[n][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}