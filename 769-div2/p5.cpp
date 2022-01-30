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

const int N = 2e5 + 5, LGN = 20;
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

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    vector<int> res(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 1, 0);
    int mx = 0;
    for (int i = 1; i <= n; i++)
        mx = max(mx, dep[i]);
    vector<int> leaves;
    for (int i = 1; i <= n; i++)
        if (dep[i] == mx)
            leaves.pb(i);

    for (int i = 1; i <= n; i++)
        res[i] = mx;

    int root = leaves[0];
    for (int i = 1; i < (int)leaves.size(); i++)
        root = lca(root, leaves[i]);

    int dis = mx - dep[leaves[0]];
    for (int i = 1; i <= n; i++)
        res[i] = min(res[i], dis + i);

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
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