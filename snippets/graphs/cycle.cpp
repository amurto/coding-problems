#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
vector<int> g[N];

// Check Cycle in Undirected Graph
bool dfsUG(int cur, vector<bool> &vis, int parent)
{
    vis[cur] = true;
    for (int e : g[cur])
    {
        if (e == parent)
            continue;
        if (vis[e] || dfsUG(cur, vis, cur))
            return true;
    }
    return false;
}

bool isCyclicUG(int n)
{
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
        if (!vis[i] && dfsUG(i, vis, -1))
            return true;
    return false;
}

// Check Cycle in Directed Graph
bool dfsDG(int cur, vector<bool> &vis, vector<bool> &st)
{
    vis[cur] = st[cur] = true;
    for (int e : g[cur])
        if ((!vis[e] && dfsDG(e, vis, st)) || st[e])
            return true;
    st[cur] = false;
    return false;
}

bool isCyclicDG(int n)
{
    vector<bool> vis(n + 1), st(n + 1);
    for (int i = 1; i <= n; i++)
        if (!vis[i] && dfsDG(i, vis, st))
            return true;
    return false;
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
        // g[v].pb(u);
    }
    return 0;
}