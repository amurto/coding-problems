// https://practice.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string/0
// Count Palindrome Sub-Strings of a String

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        char str[n];
        for (int i = 0; i < n; i++)
            str[i] = s[i];

        int dp[n][n];
        int P[n][n];
        memset(dp, 0, sizeof(dp));
        memset(P, 0, sizeof(P));
        for (int i = 0; i < n; i++)
            P[i][i] = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (str[i] == str[i + 1])
            {
                dp[i][i + 1] = 1;
                P[i][i + 1] = 1;
            }
        }
        for (int gap = 2; gap < n; gap++)
        {
            for (int i = 0; i < n - gap; i++)
            {
                int j = i + gap;
                if (str[i] == str[j] && P[i + 1][j - 1])
                    P[i][j] = 1;
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + P[i][j];
            }
        }

        cout << dp[0][n - 1] << endl;
    }
    return 0;
}
