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
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int solve()
{
    int n, k, res = 0;
    cin >> n >> k;
    vector<int> p(n + 1), q(n + 1), ids(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> q[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i1, int i2)
         { return p[i1] < p[i2]; });
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    dp[0][0] = 1;
    for (int i = n; i > 0; i--)
    {
        vector<vector<int>> tdp(n + 1, vector<int>(k + 1));
        for (int j = 0; j < q[ids[i]]; j++)
        {
            for (int t = 0; t <= k; t++)
                tdp[j][t] = add(tdp[j][t], dp[j][t]);
            for (int t = 1; t <= k; t++)
                tdp[q[ids[i]]][t] = add(tdp[q[ids[i]]][t], dp[j][t - 1]);
        }
        for (int j = q[ids[i]] + 1; j <= n; j++)
            for (int t = 1; t <= k; t++)
                tdp[j][t] = add(tdp[j][t], dp[j][t - 1]);
        swap(dp, tdp);
    }
    for (int i = 0; i <= n; i++)
        res = add(res, dp[i][k]);
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