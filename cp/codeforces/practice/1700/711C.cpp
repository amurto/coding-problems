// https://codeforces.com/contest/711/problem/C
// Coloring Trees

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 102;
ll p[N][N], c[N], inf = 1e15;

ll solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    c[0] = m + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> p[i][j];
    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(N, vector<ll>(N, inf)));
    for (int i = 1; i <= m; i++)
        dp[n + 1][k][i] = 0;
    for (int i = n; i >= 1; i--)
    {
        int l1 = (c[i]) ? c[i] : 1, r1 = (c[i]) ? c[i] : m;
        int l2 = (c[i - 1]) ? c[i - 1] : 1, r2 = (c[i - 1]) ? c[i - 1] : m;
        for (int g = 0; g <= n; g++)
            for (int j = l1; j <= r1; j++)
                for (int last = l2; last <= r2; last++)
                    dp[i][g][last] = min(dp[i][g][last], (c[i] != j) * p[i][j] + dp[i + 1][g + (j != last)][j]);
    }
    return (dp[1][0][m + 1] >= inf) ? -1 : dp[1][0][m + 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}