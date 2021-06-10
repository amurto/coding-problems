// https://codeforces.com/contest/1092/problem/E
// Minimal Diameter Forest

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e3 + 5;
vector<int> g[N];
bool vis[N];
int dep[N], par[N];
vector<int> ids;

int dfs(int cur, int last, int d)
{
    vis[cur] = true;
    par[cur] = last;
    dep[cur] = d;
    int mx = cur;
    for (int e : g[cur])
    {
        if (e != last)
        {
            int v = dfs(e, cur, d + 1);
            if (dep[v] > dep[mx])
                mx = v;
        }
    }
    return mx;
}

int find_diam(int cur)
{
    int root = dfs(cur, -1, 1);
    int leaf = dfs(root, -1, 1);
    vector<int> nodes;
    while (leaf != -1)
    {
        nodes.pb(leaf);
        leaf = par[leaf];
    }
    int sz = nodes.size();
    int center = nodes[sz / 2];
    ids.pb(center);
    dep[center] = sz / 2;
    return sz - 1;
}

void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; i++)
        vis[i] = false;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int diam = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            diam = max(diam, find_diam(i));
    int id = ids[0];
    for (int i : ids)
        if (dep[i] >= dep[id])
            id = i;
    for (int i : ids)
    {
        if (i != id)
        {
            edges.pb({id, i});
            g[id].pb(i);
            g[i].pb(id);
        }
    }
    cout << find_diam(1) << "\n";
    for (pair<int, int> e : edges)
        cout << e.first << " " << e.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}