// https://codeforces.com/contest/1398/problem/D
// Colored Rectangles

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int x;
    vector<int> sz(3);
    vector<vector<int>> arr(3);
    cin >> sz[0] >> sz[1] >> sz[2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < sz[i]; j++)
        {
            cin >> x;
            arr[i].pb(x);
        }
    }
    for (int i = 0; i < 3; i++)
        sort(arr[i].rbegin(), arr[i].rend());
    vector<vector<vector<int>>> dp(sz[0] + 1, vector<vector<int>>(sz[1] + 1, vector<int>(sz[2] + 1)));
    for (int i = sz[0]; i >= 0; i--)
    {
        for (int j = sz[1]; j >= 0; j--)
        {
            for (int k = sz[2]; k >= 0; k--)
            {
                // i j
                if (i < sz[0] && j < sz[1])
                    dp[i][j][k] = max(dp[i][j][k], arr[0][i] * arr[1][j] + dp[i + 1][j + 1][k]);
                // j k
                if (j < sz[1] && k < sz[2])
                    dp[i][j][k] = max(dp[i][j][k], arr[1][j] * arr[2][k] + dp[i][j + 1][k + 1]);
                // i k
                if (i < sz[0] && k < sz[2])
                    dp[i][j][k] = max(dp[i][j][k], arr[0][i] * arr[2][k] + dp[i + 1][j][k + 1]);
            }
        }
    }
    return dp[0][0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}