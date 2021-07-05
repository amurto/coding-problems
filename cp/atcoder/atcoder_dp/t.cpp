// https://atcoder.jp/contests/dp/tasks/dp_t
// T - Permutation
// Permutation DP

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
    int n;
    string str;
    cin >> n >> str;
    vector<vector<int>> dp(n + 1, vector<int>(n + 2));
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        char ch = str[i - 2];
        if (ch == '<')
            for (int j = 1; j <= i; j++)
                dp[i][j] = add(dp[i][j - 1], dp[i - 1][j - 1]);
        else
            for (int j = i; j >= 1; j--)
                dp[i][j] = add(dp[i][j + 1], dp[i - 1][j]);
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum = add(sum, dp[n][i]);
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}