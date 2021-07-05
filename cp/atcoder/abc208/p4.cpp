#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e9 + 5;

ll solve()
{
    int n, m, u, v, w;
    ll sum = 0;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        dp[u - 1][v - 1] = w;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                if (dp[i][j] < inf)
                    sum += 1ll * dp[i][j];
            }
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}