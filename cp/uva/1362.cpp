// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4108
// 1362 - Exploring Pyramids

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    while (cin >> str)
    {
        int n = str.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int gap = 2; gap < n; gap++)
            for (int i = 0, j = gap; j < n; i++, j++)
                for (int k = i + 2; k <= j; k++)
                    if (str[i] == str[k])
                        dp[i][j] = (dp[i][j] + (dp[i + 1][k - 1] * 1ll * dp[k][j]) % MOD) % MOD;
        cout << dp[0][n - 1] << "\n";
    }
    return 0;
}