#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    int mn = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], (i == arr[j]) + dp[i - 1][j - 1]);
            if (dp[i][j] >= k)
                mn = min(mn, j - i);
        }
    }
    return (mn == n) ? -1 : mn;
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