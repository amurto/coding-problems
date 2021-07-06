// https://codeforces.com/contest/859/problem/D
// Third Month Insanity

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double solve()
{
    int n;
    cin >> n;
    int t = 1 << n;
    vector<vector<int>> p(t, vector<int>(t));
    for (int i = 0; i < t; i++)
        for (int j = 0; j < t; j++)
            cin >> p[i][j];
    vector<vector<double>> w(n + 1, vector<double>(t)), dp(n + 1, vector<double>(t));
    for (int i = 0; i < t; i++)
        w[0][i] = 1.0;
    for (int i = 1; i <= n; i++)
    {
        int cur = i - 1;
        int r = 1 << i, h = 1 << cur;
        double pts = 1.0 * (1 << cur);
        for (int j = 0; j < t; j += r)
        {
            for (int c = j; c < j + h; c++)
                for (int v = j + h; v < j + r; v++)
                    w[i][c] += w[i - 1][c] * 1.0 * p[c][v] / 100.0 * w[i - 1][v];
            for (int c = j + h; c < j + r; c++)
                for (int v = j; v < j + h; v++)
                    w[i][c] += w[i - 1][c] * 1.0 * p[c][v] / 100.0 * w[i - 1][v];
            for (int c = j; c < j + h; c++)
                for (int v = j + h; v < j + r; v++)
                    dp[i][c] = max(dp[i][c], dp[i - 1][c] + dp[i - 1][v] + w[i][c] * pts);
            for (int c = j + h; c < j + r; c++)
                for (int v = j; v < j + h; v++)
                    dp[i][c] = max(dp[i][c], dp[i - 1][c] + dp[i - 1][v] + w[i][c] * pts);
        }
    }
    double res = 0;
    for (int i = 0; i < t; i++)
        res = max(res, dp[n][i]);
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