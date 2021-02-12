// https://codeforces.com/contest/467/problem/C
// George and Job

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n + 1);
    vector<ll> pre(n + 1);
    vector<vector<ll>> dp(n + 2, vector<ll>(k + 1));
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + arr[i];
    for (int i = 0; i <= k; i++)
        dp[n + 1][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][k] = 0;
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < k; j++)
        {
            dp[i][j] = dp[i + 1][j];
            if (i + m - 1 <= n)
                dp[i][j] = max(dp[i][j], pre[i + m - 1] - pre[i - 1] + dp[i + m][j + 1]);
        }
    }
    cout << dp[0][0] << "\n";
    return 0;
}