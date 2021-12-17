#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5, LGN = 19;
vector<int> g[N];
int up[N][LGN + 1], tin[N], tout[N], dep[N], timer = 0;

void dfs(int cur, int last, int dd)
{
    tin[cur] = ++timer;
    dep[cur] = dd;
    up[cur][0] = last;
    for (int i = 1; i <= LGN; i++)
        up[cur][i] = up[up[cur][i - 1]][i - 1];
    for (int e : g[cur])
        if (e != last)
            dfs(e, cur, dd + 1);
    tout[cur] = timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LGN; i >= 0; i--)
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

int k_ancestor(int u, int k)
{
    int d = dep[u], tmp = k;
    for (int i = LGN; i >= 0; i--)
    {
        if ((1 << i) <= k)
        {
            u = up[u][i];
            k -= (1 << i);
        }
    }
    return (d - dep[u] == tmp) ? u : -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 1, 0);
    return 0;
}