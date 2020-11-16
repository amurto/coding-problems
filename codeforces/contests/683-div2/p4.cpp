#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, res=0;
    cin >> n >> m;
    string str1, str2;
    cin >> str1 >> str2;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j] - 1, dp[i][j - 1] - 1);
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = max({2, dp[i][j], 2 + dp[i - 1][j - 1]});
            res = max(res, dp[i][j]);
        }
    }
    cout << res << "\n";
    return 0;
}