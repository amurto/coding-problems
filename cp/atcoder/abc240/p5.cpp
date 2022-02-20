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

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> tin(n + 1), tout(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    // Lambda recursive function
    auto dfs = [&](const auto &self, int cur, int last, int t) -> int
    {
        tin[cur] = tout[cur] = t;
        int mx = t - 1;
        for (int e : g[cur])
        {
            if (e != last)
            {
                tout[cur] = self(self, e, cur, mx + 1);
                mx = tout[cur];
            }
        }
        return tout[cur];
    };
    dfs(dfs, 1, 1, 1);
    for (int i = 1; i <= n; i++)
        cout << tin[i] << " " << tout[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}