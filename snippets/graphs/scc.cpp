// Strongly Connected Components

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Kosaraju's Algorithm
const int N = 1e5 + 5;
vector<bool> vis;
vector<int> g[N], gt[N], order, scc;

void dfs1(int cur)
{
    vis[cur] = true;
    for (int e : g[cur])
        if (!vis[e])
            dfs1(e);
    order.pb(cur);
}

void dfs2(int cur)
{
    vis[cur] = true;
    scc.pb(cur);
    for (int e : gt[cur])
        if (!vis[e])
            dfs2(e);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        gt[v].pb(u);
    }
    vis.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(i);
    vis.assign(n + 1, false);
    reverse(order.begin(), order.end());
    for (int node : order)
    {
        if (vis[node])
            continue;
        dfs2(node);
        scc.clear();
    }
    return 0;
}