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

ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<ll> h(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll root = 0;
    for (int i = 1; i <= n; i++)
        if (h[i] > h[root])
            root = i;
    // Lambda recursive function
    auto dfs = [&](const auto &self, int cur, int last) -> ll
    {
        for (int e : g[cur])
            if (e != last)
                dp[cur] = max(dp[cur], self(self, e, cur));
        res += max(0ll, h[cur] - dp[cur]);
        dp[cur] = max(dp[cur], h[cur]);
        return dp[cur];
    };
    dfs(dfs, root, root);
    array<ll, 2> cnt{0, 0};
    for (int e : g[root])
    {
        cnt[1] = max(cnt[1], dp[e]);
        if (cnt[0] < cnt[1])
            swap(cnt[0], cnt[1]);
    }
    res += max(0ll, h[root] - cnt[1]);
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