// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1159
// 10218 - Let's Dance !!!

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double dp[1001][1001];

/*
// Recursion with memo
double solve(double p, int gm, int rem)
{
    if (rem == 0)
        return gm % 2 == 0;
    double &ret = dp[gm][rem];
    if (ret == ret)
        return ret;
    dp[gm][rem] = p * solve(p, gm + 1, rem - 1) + (1.0 - p) * solve(p, gm, rem - 1);
    return dp[gm][rem];
}
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, w, c;
    while (cin >> m >> w >> c && (m || w))
    {
        memset(dp, 0.0, sizeof(dp));
        double p = m * 1.0 / (m + w);
        dp[0][0] = 1.0;
        dp[0][1] = 0.0;
        for (int rem = 1; rem <= c; rem++)
        {
            dp[rem][0] = (1.0 - p) * dp[rem - 1][0] + p * dp[rem - 1][1];
            dp[rem][1] = p * dp[rem - 1][0] + (1.0 - p) * dp[rem - 1][1];
        }

        double res = dp[c][0];
        cout << fixed << setprecision(7) << res << "\n";
    }
}