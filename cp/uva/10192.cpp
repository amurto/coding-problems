// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1133
// 10192 - Vacation

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    string str1, str2;
    while (cin >> str1)
    {
        if (str1 == "#")
            break;
        cin >> str2;
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j]= max(dp[i][j], 1 + dp[i-1][j-1]);
            }
        }
        cout << "Case #" << t << ": you can visit at most " << dp[n][m] << " cities.\n";
        t++;
    }
    return 0;
}