// https://codeforces.com/contest/1221/problem/D
// Make The Fence Great Again

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int d(int p1, int p2)
{
    if (p1 < p2)
        return 3;
    return min(3, p1 - p2);
}

ll solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    a[n] = 1e9 + 7;
    vector<vector<ll>> dp(n + 1, vector<ll>(4, 1e17));
    dp[n][3] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j != 0)
                dp[i][j] = min(dp[i][j], dp[i + 1][d(a[i], a[i + 1])]);
            if (j != 1)
                dp[i][j] = min(dp[i][j], b[i] + dp[i + 1][d(a[i] + 1, a[i + 1])]);
            if (j != 2)
                dp[i][j] = min(dp[i][j], 2 * b[i] + dp[i + 1][d(a[i] + 2, a[i + 1])]);
        }
    }
    return dp[0][3];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}