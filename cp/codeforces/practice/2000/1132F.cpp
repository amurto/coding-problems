// https://codeforces.com/contest/1132/problem/F
// Clear the String

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int gap = 1; gap < n; gap++)
    {
        for (int l = 0, r = gap; r < n; l++, r++)
        {
            dp[l][r] = 1 + dp[l + 1][r];
            for (int j = l + 1; j <= r; j++)
                if (str[l] == str[j])
                    dp[l][r] = min(dp[l][r], dp[j][r] + ((j - l > 1) ? dp[l + 1][j - 1] : 0));
        }
    }
    return dp[0][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}