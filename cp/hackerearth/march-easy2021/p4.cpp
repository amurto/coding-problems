#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e6 + 5;

int solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    a[0] = b[0] = -inf;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    vector<vector<vector<int>>> dp(n + 2, vector<vector<int>>(m + 2, vector<int>(2)));
    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            dp[i][j][0] = dp[i][j + 1][0];
            if (b[j] > a[i])
                dp[i][j][0] = max(dp[i][j][0], 1 + dp[i + 1][j][1]);
            dp[i][j][1] = dp[i + 1][j][1];
            if (a[i] > b[j])
                dp[i][j][1] = max(dp[i][j][1], 1 + dp[i][j + 1][0]);
        }
    }
    return max(dp[0][0][0], dp[0][0][1]);
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