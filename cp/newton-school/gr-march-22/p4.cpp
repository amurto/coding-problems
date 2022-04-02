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

const ll inf = 1e18 + 7;
void solve()
{
    int n, m;
    ll res = 0, mn = inf;
    cin >> n >> m;
    vector<ll> arr(n + 1), dp(n + 1), in_deg(n + 1), out_deg(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        in_deg[v]++;
        out_deg[u]++;
        g[u].pb(v);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in_deg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int sz = (int)q.size();
        while (sz > 0)
        {
            int cur = q.front();
            q.pop();
            ll ops = 0;
            if (arr[cur] <= out_deg[cur] && out_deg[cur] > 0)
            {
                ops = (arr[cur] + dp[cur]) / out_deg[cur];
                ll rem = (arr[cur] + dp[cur]) % out_deg[cur];
                rem = out_deg[cur] - rem;
                if (rem <= out_deg[cur] - arr[cur])
                    mn = min(mn, rem);
            }
            res += ops;
            for (int e : g[cur])
            {
                dp[e] += ops;
                if (--in_deg[e] == 0)
                    q.push(e);
            }
            sz--;
        }
    }
    if (mn >= inf)
        mn = -1;
    cout << res << " " << mn << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}