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

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2)));
    vector<vector<int>> st(n + 1, vector<int>(2));
    dp[0][0][0] = 1;
    st[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 2; k++)
                dp[i][(j + arr[i]) % 3][(k + arr[i]) % 2] = add(dp[i][(j + arr[i]) % 3][(k + arr[i]) % 2], dp[i - 1][j][k]);
        st[i] = st[i - 1];
        for (int j = 0; j < 2; j++)
            st[i][(j + arr[i]) % 2] = add(st[i][(j + arr[i]) % 2], st[i - 1][j]);
    }
    res = add(dp[n][0][0], st[n][1]);
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