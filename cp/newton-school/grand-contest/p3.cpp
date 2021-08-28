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

const int N = 3005;
const ll inf = 1e18;
vector<pii> g[N];
void solve()
{
    int n, m, u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n, inf));
    vector<ll> dis(n + 1, inf);
    dp[1][0] = dis[1] = 0;
    for (int t = 1; t < n; t++)
    {
        for (int i = 2; i <= n; i++)
        {
            for (pii e : g[i])
            {
                dp[i][t] = min(dp[i][t], dp[e.first][t - 1] + 1ll * t * e.second);
                dis[i] = min(dis[i], dp[i][t]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dis[i] >= inf)
            dis[i] = -1;
        cout << dis[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}