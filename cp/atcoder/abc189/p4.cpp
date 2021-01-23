#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    dp[n][1] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == "AND")
        {
            dp[i][0] = dp[i + 1][0] + dp[i + 1][0];
            dp[i][1] = dp[i + 1][0] + dp[i + 1][1];
        }
        else
        {
            dp[i][0] = dp[i + 1][0] + dp[i + 1][1];
            dp[i][1] = dp[i + 1][1] + dp[i + 1][1];
        }
    }
    return dp[0][0] + dp[0][1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}