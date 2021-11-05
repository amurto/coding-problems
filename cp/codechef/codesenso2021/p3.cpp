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

const int MOD = 1e9 + 7, N = 1e5 + 5;
vector<int> g[N];
int two[N], arr[N];

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

int dfs(vector<vector<int>> &dp, int cur, int last)
{
    int res = 0;
    // dp[0] -> negative 2s
    // dp[1] -> positive 2s
    dp[cur][0] = dp[cur][1] = -1;
    int v = abs(arr[cur]) - 1;
    if (arr[cur] < 0)
        dp[cur][0] = v;
    else
        dp[cur][1] = v;
    for (int e : g[cur])
    {
        if (e != last)
        {
            res = max(res, dfs(dp, e, cur));
            if (dp[cur][0] >= 0 && dp[e][0] >= 0)
                res = max(res, dp[cur][0] + dp[e][0]);
            if (dp[cur][1] >= 0 && dp[e][1] >= 0)
                res = max(res, dp[cur][1] + dp[e][1]);
            if (arr[cur] < 0)
            {
                if (dp[e][1] >= 0)
                    dp[cur][0] = max(dp[cur][0], dp[e][1] + v);
                if (dp[e][0] >= 0)
                    dp[cur][1] = max(dp[cur][1], dp[e][0] + v);
            }
            else
            {

                if (dp[e][0] >= 0)
                    dp[cur][0] = max(dp[cur][0], dp[e][0] + v);
                if (dp[e][1] >= 0)
                    dp[cur][1] = max(dp[cur][1], dp[e][1] + v);
            }
        }
    }
    res = max(res, dp[cur][1]);
    return res;
}

int solve()
{
    int n, u, v, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    if (n == 1)
        return add(0, arr[1]);
    res = dfs(dp, 1, 1);
    return two[res];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    two[0] = 1;
    for (int i = 1; i < N; i++)
        two[i] = mul(two[i - 1], 2);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}