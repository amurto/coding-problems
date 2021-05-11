#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int K = 62;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(K));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < K; j++)
            dp[i][j] = -j + 30;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < K; j++)
        {
            int v = j - 30;
            if (arr[i] <= v)
            {
                dp[i][j] = max(dp[i - 1][j] + arr[i], dp[i][j] + arr[i]);
                mx = max(mx, dp[i][j]);
            }
        }
    }
    cout << mx << "\n";
    return 0;
}