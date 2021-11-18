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

const ll inf = 1e18;
ll solve()
{
    int h, w, k;
    ll res = inf;
    cin >> h >> w >> k;
    vector<int> di = {-1, 0}, dj = {0, -1};
    vector<vector<ll>> grid(h, vector<ll>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];
    auto calc = [&](ll x)
    {
        vector<vector<vector<ll>>> dp(h, vector<vector<ll>>(w, vector<ll>(k + 1, inf)));
        if (grid[0][0] >= x)
            dp[0][0][1] = grid[0][0];
        else if (grid[0][0] == x)
        {
            dp[0][0][0] = 0;
            dp[0][0][1] = grid[0][0];
        }
        else
            dp[0][0][0] = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (i + j > 0)
                {
                    for (int dir = 0; dir < 2; dir++)
                    {
                        int ti = i + di[dir], tj = j + dj[dir];
                        if (ti >= 0 && tj >= 0)
                        {
                            if (grid[i][j] > x)
                            {
                                for (int t = 1; t <= k; t++)
                                    if (dp[ti][tj][t - 1] < inf)
                                        dp[i][j][t] = min(dp[i][j][t], dp[ti][tj][t - 1] + grid[i][j]);
                            }
                            else if (grid[i][j] == x)
                            {
                                for (int t = 1; t <= k; t++)
                                    if (dp[ti][tj][t - 1] < inf)
                                        dp[i][j][t] = min(dp[i][j][t], dp[ti][tj][t - 1] + grid[i][j]);
                                for (int t = 0; t <= k; t++)
                                    dp[i][j][t] = min(dp[i][j][t], dp[ti][tj][t]);
                            }
                            else
                            {
                                for (int t = 0; t <= k; t++)
                                    dp[i][j][t] = min(dp[i][j][t], dp[ti][tj][t]);
                            }
                        }
                    }
                }
            }
        }
        return dp[h - 1][w - 1][k];
    };
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            res = min(res, calc(grid[i][j]));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}