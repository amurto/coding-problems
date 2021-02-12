// https://codeforces.com/contest/427/problem/C
// Checkposts

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5, MOD = 1e9 + 7;
vector<bool> vis;
ll cost[N];
vector<int> g[N], gt[N], order, scc;

void dfs1(int cur)
{
    vis[cur] = true;
    for (int e : g[cur])
        if (!vis[e])
            dfs1(e);
    order.pb(cur);
}

ll dfs2(int cur)
{
    ll res = cost[cur];
    vis[cur] = true;
    scc.pb(cur);
    for (int e : gt[cur])
        if (!vis[e])
            res = min(res, dfs2(e));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    cin >> m;
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
    ll res = 0, ways = 1;
    for (int node : order)
    {
        if (vis[node])
            continue;
        ll c = dfs2(node), w = 0;
        res += c;
        for (int e : scc)
            if (cost[e] == c)
                w++;
        scc.clear();
        ways *= w;
        ways %= MOD;
    }
    cout << res << " " << ways << "\n";
    return 0;
}