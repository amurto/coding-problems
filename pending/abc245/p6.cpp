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

// Kosaraju's Algorithm
const int N = 2e5 + 5;
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

int solve()
{
    int n, m, u, v, res = 0;
    cin >> n >> m;
    vector<int> pos(n + 1);
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
    queue<int> q;
    for (int node : order)
    {
        if (vis[node])
            continue;
        dfs2(node);
        int sz = (int)scc.size();
        if (sz > 1)
        {
            for (int e : scc)
            {
                pos[e] = true;
                q.push(e);
            }
        }
        scc.clear();
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int e : gt[cur])
        {
            if (!pos[e])
            {
                pos[e] = true;
                q.push(e);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        res += pos[i];
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