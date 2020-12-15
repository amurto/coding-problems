// https://codeforces.com/contest/604/problem/C
// Alternative Thinking

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string str;
    cin >> str;
    int dp[n + 1][3][2];
    dp[n][0][0] = dp[n][1][0] = dp[n][2][0] = dp[n][0][1] = dp[n][1][1] = dp[n][2][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int cur = str[i] - '0';
        dp[i][1][cur] = max(dp[i + 1][1][cur], 1 + dp[i + 1][2][cur ^ 1]);
        dp[i][1][cur ^ 1] = 1 + dp[i + 1][1][cur];
        dp[i][0][cur] = 1 + dp[i + 1][0][cur ^ 1];
        dp[i][2][cur] = 1 + dp[i + 1][2][cur ^ 1];
        dp[i][0][cur ^ 1] = dp[i + 1][0][cur ^ 1];
        dp[i][2][cur ^ 1] = dp[i + 1][2][cur ^ 1];
        dp[i][0][cur ^ 1] = max(dp[i][0][cur ^ 1], 1 + dp[i + 1][1][cur]);
    }
    cout << max(dp[0][0][0], dp[0][0][1]) << "\n";
    return 0;
}