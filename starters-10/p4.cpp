#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 2e9 + 5;
int di[2] = {-1, 0}, dj[2] = {0, -1};
int solve()
{
    int n, k, res = -1;
    cin >> n >> k;
    vector<string> grid(n);
    vector<vector<int>> arr(n, vector<int>(n));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -inf)));
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    dp[0][0][0] = arr[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char cur = grid[i][j];
            if (i + j > 0)
            {
                for (int dir = 0; dir < 2; dir++)
                {
                    int ti = i + di[dir], tj = j + dj[dir];
                    if (ti >= 0 && ti < n && tj >= 0 && tj < n)
                    {
                        for (int t = 0; t <= k; t++)
                        {
                            if (t == 0)
                            {
                                if (cur != '#' && dp[ti][tj][t] > 0)
                                    dp[i][j][t] = max(dp[i][j][t], dp[ti][tj][t] + arr[i][j]);
                            }
                            else if (t == k)
                            {
                                if (cur != '#' && dp[ti][tj][t] > 0)
                                    dp[i][j][t] = max(dp[i][j][t], dp[ti][tj][t] + arr[i][j]);
                                if (dp[ti][tj][t - 1] > 0)
                                    dp[i][j][t] = max(dp[i][j][t], dp[ti][tj][t - 1] + arr[i][j]);
                            }
                            else
                            {
                                if (dp[ti][tj][t - 1] > 0)
                                    dp[i][j][t] = max(dp[i][j][t], dp[ti][tj][t - 1] + arr[i][j]);
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i <= k; i++)
        res = max(res, dp[n - 1][n - 1][i]);
    return res <= 0 ? -1 : res;
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