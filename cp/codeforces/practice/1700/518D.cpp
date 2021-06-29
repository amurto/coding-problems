// https://codeforces.com/contest/518/problem/D
// Ilya and Escalator

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double solve()
{
    int n, t;
    double p;
    cin >> n >> p >> t;
    double q = 1.0 - p, res = 0;
    vector<vector<double>> dp(t + 1, vector<double>(n + 2));
    dp[1][1] = q;
    dp[1][2] = p;
    for (int i = 2; i <= t; i++)
    {
        dp[i][1] = dp[i - 1][1] * q;
        for (int j = 2; j <= n; j++)
            dp[i][j] = dp[i - 1][j] * q + dp[i - 1][j - 1] * p;
        dp[i][n + 1] = dp[i - 1][n + 1] + dp[i - 1][n] * p;
    }
    for (int i = 1; i <= n + 1; i++)
        res += 1.0 * dp[t][i] * (i - 1);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    cout << solve() << "\n";
    return 0;
}