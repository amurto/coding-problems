// https://codeforces.com/contest/835/problem/C
// Star sky

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q, c, x, y, s;
    cin >> n >> q >> c;
    c++;
    int dp[c][101][101];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> s;
        for (int j = 0; j < c; j++)
            dp[j][x][y] += (s + j) % c;
    }
    for (int t = 0; t < c; t++)
        for (int i = 1; i <= 100; i++)
            for (int j = 1; j <= 100; j++)
                dp[t][i][j] += dp[t][i - 1][j] + dp[t][i][j - 1] - dp[t][i - 1][j - 1];
    while (q-- > 0)
    {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= c;
        int sum = dp[t][x2][y2] - dp[t][x1 - 1][y2] - dp[t][x2][y1 - 1] + dp[t][x1 - 1][y1 - 1];
        cout << sum << "\n";
    }
    return 0;
}