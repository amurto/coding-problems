#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e15;

ll solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(2, -inf)));
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(i, k); j++)
        {
            // 0
            // dp[i][j][0]
            dp[i][j][0] = max(dp[i - 1][j - 1][1], dp[i - 1][j][0]);
            // 1
            // dp[i][j][1]
            dp[i][j][1] = max(dp[i][j][1], arr[i] * j + max({dp[i - 1][j - 1][1], dp[i - 1][j][0], dp[i - 1][j][1]}));
        }
    }
    ll res = dp[n][k][1];
    for (int i = 1; i <= n; i++)
        res = max(res, dp[i][k][1]);
    return res;
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