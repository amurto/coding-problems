#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n + 5, vector<int>(2)), tdp(n + 5, vector<int>(2));
    // dp[mex][0] -> mex is maximum
    // dp[mex][1] -> mex+1 is maximum;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        vector<pii> upd;
        int x = arr[i];
        // last_mex is x-1

        if (x - 1 >= 0)
        {
            upd.pb({x - 1, 1});
            tdp[x - 1][1] = 0;
            // x-1 is max : dp[x-1][0]
            tdp[x - 1][1] = add(tdp[x - 1][1], dp[x - 1][0]);
            // x-1 is not max : dp[x-1][1]
            tdp[x - 1][1] = add(tdp[x - 1][1], dp[x - 1][1]);
        }

        // last_mex is x
        // dp[x][0], dp[x][1]
        upd.pb({x + 1, 0});
        tdp[x + 1][0] = 0;

        tdp[x + 1][0] = add(tdp[x + 1][0], dp[x][0]);

        // last_mex is x+1
        // dp[x+1][0], dp[x+1][1]
        tdp[x + 1][0] = add(tdp[x + 1][0], dp[x + 1][0]);

        upd.pb({x + 1, 1});
        tdp[x + 1][1] = 0;

        tdp[x + 1][1] = add(tdp[x + 1][1], dp[x + 1][1]);
        for (pii p : upd)
        {
            res = add(res, tdp[p.first][p.second]);
            dp[p.first][p.second] = add(dp[p.first][p.second], tdp[p.first][p.second]);
        }
    }
    return res;
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