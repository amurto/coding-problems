// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1558
// 10617 - Again Palindrome

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string str;
        cin >> str;
        int n = str.length();
        vector<vector<ll>> dp(n, vector<ll>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int i = 0; i < n - 1; i++)
            if (str[i] == str[i + 1])
                dp[i][i + 1] = 3;
            else
                dp[i][i + 1] = 2;
        for (int gap = 2; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (str[i] == str[j])
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
                else
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
        cout << dp[0][n - 1] << "\n";
    }
    return 0;
}