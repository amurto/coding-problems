// https://codeforces.com/contest/118/problem/D
// Caesar's Legions

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e8;

int add(int x, int y)
{
    x += y;
    while (x > 0)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    int dp[n1 + 1][n2 + 1][2][12];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= min(n1, k1); i++)
        dp[0][0][0][i] = 1;
    for (int i = 1; i <= min(n2, k2); i++)
        dp[0][0][1][i] = 1;
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            if (i + j == 0)
                continue;
            for (int k = 0; k <= min(n1 - i, k1); k++)
            {
                int res = 0;
                if (i - 1 >= 0)
                    res = add(res, dp[i - 1][j][0][k + 1]);
                if (j - 1 >= 0)
                    res = add(res, dp[i][j - 1][1][1]);
                dp[i][j][0][k] = res;
            }
            for (int k = 0; k <= min(n2 - j, k2); k++)
            {
                int res = 0;
                if (j - 1 >= 0)
                    res = add(res, dp[i][j - 1][1][k + 1]);
                if (i - 1 >= 0)
                    res = add(res, dp[i - 1][j][0][1]);
                dp[i][j][1][k] = res;
            }
        }
    }
    cout << dp[n1][n2][0][0] << "\n";
    return 0;
}