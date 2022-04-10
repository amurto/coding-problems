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

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    x %= MOD;
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

int calc(int n)
{
    if (n == 1)
        return 1;
    int val = 0;
    vector<vector<int>> dp1(2, vector<int>(n)), dp2(2, vector<int>(n));
    dp1[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp1[0][i] = add(dp1[0][i], dp1[1][i - 1]);
        dp1[1][i] = add(dp1[1][i], add(dp1[0][i - 1], dp1[1][i - 1]));
    }
    val = add(val, dp1[1][n - 1]);
    dp2[1][0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp2[0][i] = add(dp2[0][i], dp2[1][i - 1]);
        dp2[1][i] = add(dp2[1][i], add(dp2[0][i - 1], dp2[1][i - 1]));
    }
    val = add(val, add(dp2[0][n - 1], dp2[1][n - 1]));
    return val;
}

int solve()
{
    int n, res = 1;
    cin >> n;
    vector<int> P(n), Q(n);
    vector<vector<int>> g(n + 1, vector<int>(2, -1));
    vector<bool> vis(n + 1);
    for (int i = 0; i < n; i++)
        cin >> P[i];
    for (int i = 0; i < n; i++)
        cin >> Q[i];

    for (int i = 0; i < n; i++)
    {
        if (g[P[i]][0] == -1)
            g[P[i]][0] = Q[i];
        else
            g[P[i]][1] = Q[i];
        if (g[Q[i]][0] == -1)
            g[Q[i]][0] = P[i];
        else
            g[Q[i]][1] = P[i];
    }
    // Lambda recursive function
    auto dfs = [&](const auto &self, int cur) -> int
    {
        int cnt = 1;
        vis[cur] = true;
        for (int t = 0; t < 2; t++)
            if (g[cur][t] > 0 && !vis[g[cur][t]])
                cnt += self(self, g[cur][t]);
        return cnt;
    };
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int cnt = dfs(dfs, i);
            res = mul(res, calc(cnt));
        }
    }
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