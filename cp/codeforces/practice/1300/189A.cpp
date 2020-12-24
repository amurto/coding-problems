// https://codeforces.com/contest/189/problem/A
// Cut Ribbon

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
        if (i - a >= 0 && dp[i - a] >= 0)
            dp[i] = max(dp[i], 1 + dp[i - a]);
        if (i - b >= 0 && dp[i - b] >= 0)
            dp[i] = max(dp[i], 1 + dp[i - b]);
        if (i - c >= 0 && dp[i - c] >= 0)
            dp[i] = max(dp[i], 1 + dp[i - c]);
    }
    cout << dp[n] << "\n";
    return 0;
}