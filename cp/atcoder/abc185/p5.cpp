#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i=0; i<=n; i++)
        dp[i][0] = i;
    for (int i=0;i<=m; i++)
        dp[0][i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            if (A[i-1] == B[j-1])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else 
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}