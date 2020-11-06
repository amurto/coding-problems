// https://codeforces.com/problemset/problem/893/C
// Rumor

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll dfs(vector<vector<int>> &g, vector<bool> &vis, vector<ll> &c, int cur)
{
    ll cost = c[cur];
    vis[cur] = true;
    for (int v : g[cur])
    {
        if (vis[v])
            continue;
        cost = min(cost, dfs(g, vis, c, v));
    }
    return cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<ll> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<bool> vis(n + 1);
    ll cost = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        cost += dfs(g, vis, c, i);
    }
    cout << cost << "\n";
    return 0;
}