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

const int inf = 2e9 + 7;

int solve()
{
    int n, l, k, res = inf;
    cin >> n >> l >> k;
    vector<int> pos(n), speed(n);
    vector<vector<int>> dp(k + 1, vector<int>(n, inf));
    for (int i = 0; i < n; i++)
        cin >> pos[i];
    for (int i = 0; i < n; i++)
        cin >> speed[i];
    dp[k][0] = 0;
    for (int i = 1; i < n; i++)
    {
        vector<vector<int>> tdp(k + 1, vector<int>(n, inf));
        for (int rem = 0; rem <= k; rem++)
        {
            for (int last = 0; last < i; last++)
            {
                if (dp[rem][last] < inf)
                {
                    if (rem > 0)
                        tdp[rem - 1][last] = min(tdp[rem - 1][last], speed[last] * (pos[i] - pos[i - 1]) + dp[rem][last]);
                    tdp[rem][i] = min(tdp[rem][i], speed[last] * (pos[i] - pos[i - 1]) + dp[rem][last]);
                }
            }
        }
        swap(dp, tdp);
    }
    for (int i = 0; i <= k; i++)
        for (int j = 0; j < n; j++)
            res = min(res, dp[i][j] + (l - pos[n - 1]) * speed[j]);
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