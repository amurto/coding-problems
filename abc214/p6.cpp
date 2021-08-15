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

const int MOD = 1e9 + 7, K = 26;

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
    string str;
    cin >> str;
    int n = str.length();
    if (n == 1)
        return 1;
    if (n == 2)
        return (str[0] == str[1]) ? 1 : 2;
    vector<vector<int>> dp(n, vector<int>(K));
    vector<int> pdp(n);
    dp[0][str[0] - 'a'] = dp[1][str[0] - 'a'] = 1;
    if (str[0] != str[1])
        dp[1][str[1] - 'a'] = 1;
    for (int i = 2; i < n; i++)
    {
        int cur = str[i] - 'a', sum = 1;
        dp[i] = dp[i - 2];
        for (int j = 0; j < K; j++)
            sum = add(sum, dp[i][j]);
        dp[i][cur] = add(dp[i][cur], add(sum, -dp[i - 2][cur]));
        
    }
    return 1;
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