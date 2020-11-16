// https://leetcode.com/problems/longest-common-subsequence/
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
// Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[101][101];

int LCS(string &str1, string &str2, int m, int n)
{
    if (m < 0 || n < 0)
        return 0;
    if (DP[m][n] < 0)
        if (str1[m] == str2[n])
            DP[m][n] = 1 + LCS(str1, str2, m - 1, n - 1);
        else
            DP[m][n] = max(LCS(str1, str2, m - 1, n), LCS(str1, str2, m, n - 1));
    return DP[m][n];
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length(), m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (text1[i - 1] == text2[j - 1])
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
        int m, n;
        string str1, str2;
        cin >> m >> n >> str1 >> str2;
        memset(DP, -1, sizeof(DP));
        cout << LCS(str1, str2, m - 1, n - 1) << endl;
    }
    return 0;
}