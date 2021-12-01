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

int calc(vector<int> &st, vector<vector<int>> &dis, int k)
{
    int sz = (int)st.size();
    vector<vector<int>> dp(1 << sz, vector<int>(sz, k + 1));
    dp[1][0] = 0;
    for (int mask = 2; mask < (1 << sz); mask++)
        for (int i = 1; i < sz; i++)
            if ((mask >> i) & 1)
                for (int j = 0; j < sz; j++)
                    if (j != i && ((mask >> j) & 1))
                        dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + dis[st[i]][st[j]]);
    int mn = k + 1;
    for (int i = 0; i < sz; i++)
        mn = min(mn, dp[(1 << sz) - 1][i]);
    return mn;
}

ll solve()
{
    int n, m, k, mx = 105;
    cin >> n >> m >> k;
    ll res = 0;
    vector<vector<int>> dis(n, vector<int>(n, mx));
    for (int i = 0; i < n; i++)
        dis[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        dis[u][v] = dis[v][u] = 1;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    vector<int> st = {0};
    for (int i = n - 1; (int)st.size() < k + 1 && i > 0; i--)
    {
        vector<int> cur = st;
        cur.pb(i);
        if (calc(cur, dis, k) <= k)
        {
            st = cur;
            res += (1ll << i) - 1;
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