// Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

int lcs(string str1, string str2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        string str1, str2;
        cin >> n >> m >> str1 >> str2;
        cout << lcs(str1, str2, n, m) << "\n";
    }
    return 0;
}