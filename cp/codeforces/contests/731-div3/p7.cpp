#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 4e5 + 5;
vector<int> g[N], gt[N], order, scc;
vector<bool> vis;
int T[N], self_edge[N];

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

void dfs(int cur)
{
    T[cur] = min(T[cur] + 1, 2);
    if (T[cur] > 1)
        return;
    for (int e : g[cur])
        dfs(e);
}

void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    order.clear();
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        gt[i].clear();
        T[i] = self_edge[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        if (u == v)
            self_edge[u] = 1;
        g[u].pb(v);
        gt[v].pb(u);
    }
    dfs(1);
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
        int sz = scc.size();
        for (int e : scc)
        {
            if (T[e] > 0 && (sz > 1 || self_edge[e]))
            {
                T[e] = -1;
                q.push(e);
            }
        }
        scc.clear();
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int e : g[cur])
        {
            if (T[e] != -1)
            {
                T[e] = -1;
                q.push(e);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (T[i] == 2)
        {
            T[i] = 2;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int e : g[cur])
        {
            if (T[e] != -1 && T[e] != 2)
            {
                T[e] = 2;
                q.push(e);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << T[i] << " ";
    cout << "\n";
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