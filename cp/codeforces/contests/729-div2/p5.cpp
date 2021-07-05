#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int MOD;
int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int solve()
{
    int n, res = 0;
    cin >> n >> MOD;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3000, vector<int>(3)));
    dp[0][1500][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int d = 100; d < 2900; d++)
        {
            for (int t = 1 - i; t <= i - 1; t++)
            {
                if (t < 0)
                    for (int e = 0; e <= 2; e++)
                        dp[i][d + t][0] = add(dp[i][d + t][0], mul(i - abs(t), dp[i - 1][d][e]));
                else if (t == 0)
                    for (int e = 0; e <= 2; e++)
                        dp[i][d + t][e] = add(dp[i][d + t][e], mul(i, dp[i - 1][d][e]));
                else
                    for (int e = 0; e <= 2; e++)
                        dp[i][d + t][2] = add(dp[i][d + t][2], mul(i - t, dp[i - 1][d][e]));
            }
        }
    }
    for (int d = 1501; d < 2900; d++)
        res = add(res, dp[n][d][0]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}