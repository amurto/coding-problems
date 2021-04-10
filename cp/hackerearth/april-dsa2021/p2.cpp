#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, inf = 1e7;
    string a, b;
    cin >> n >> a >> b;
    if (n == 1)
        return a != b;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2)));
    if (b[n - 1] == '0')
    {
        dp[n - 1][1][0] = 0;
        dp[n - 1][1][1] = inf;
        if (a[n - 1] == '1')
            dp[n - 1][0][0] = dp[n - 1][0][1] = 1;
    }
    else
    {
        dp[n - 1][1][0] = inf;
        dp[n - 1][1][1] = 0;
        if (a[n - 1] == '0')
            dp[n - 1][0][0] = dp[n - 1][0][1] = 1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        int nxt = a[i + 1] - '0';
        for (int j = 0; j < 2; j++)
        {
            for (int last = 0; last < 2; last++)
            {
                int cur = (j == 1) ? last : a[i] - '0', req = b[i] - '0';
                if (req == cur)
                    dp[i][j][last] = dp[i + 1][0][0];
                else
                {
                    dp[i][j][last] = 1 + dp[i + 1][0][0];
                    if (nxt == req)
                        dp[i][j][last] = min(dp[i][j][last], 1 + dp[i + 1][1][cur]);
                }
            }
        }
    }
    return dp[0][0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}