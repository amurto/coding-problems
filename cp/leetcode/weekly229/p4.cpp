#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void lps(vector<vector<int>> &dp, string word, int n)
{
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0; i < n - gap; i++)
        {
            int j = i + gap;
            if (word[i] == word[j])
            {
                if (gap == 1)
                    dp[i][j] = 2;
                else
                    dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
}

int longestPalindrome(string word1, string word2)
{
    int n = word1.length(), m = word2.length(), mx = 0;
    reverse(word2.begin(), word2.end());
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
        }
    }
    vector<vector<int>> suf1(n + 1, vector<int>(n + 1)), suf2(m + 1, vector<int>(m + 1));
    lps(suf1, word1, n);
    lps(suf2, word2, m);
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (dp[i][m] > 0)
            res = max(res, 2 * dp[i][m] + suf1[i][n - 1]);
    for (int j = 1; j <= m; j++)
        if (dp[n][j] > 0)
            res = max(res, 2 * dp[n][j] + suf2[j][m - 1]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string word1, word2;
    cin >> word1 >> word2;
    cout << longestPalindrome(word1, word2) << "\n";
    return 0;
}