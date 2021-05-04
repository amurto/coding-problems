#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 5e5 + 5, LGN = 20;
vector<int> g[N];
int up[N][LGN + 1], mx[N][LGN + 1], arr[N], tin[N], tout[N], dep[N], timer = 0;

void dfs(int cur, int last, int d)
{
    tin[cur] = ++timer;
    dep[cur] = d;
    up[cur][0] = last;
    mx[cur][0] = max(arr[cur], arr[last]);
    for (int i = 1; i <= LGN; i++)
    {
        up[cur][i] = up[up[cur][i - 1]][i - 1];
        mx[cur][i] = max(mx[cur][i - 1], mx[up[cur][i - 1]][i - 1]);
    }
    for (int e : g[cur])
        if (e != last)
            dfs(e, cur, d + 1);
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

int mx_node(int u, int k)
{
    int mxn = arr[u];
    for (int i = LGN; i >= 0; i--)
    {
        if ((1 << i) <= k)
        {
            mxn = max(mxn, mx[u][i]);
            u = up[u][i];
            k -= (1 << i);
        }
    }
    return mxn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, u, v;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 1, 0);
    while (q-- > 0)
    {
        cin >> u >> v;
        int anc = lca(u, v);
        cout << max(mx_node(u, dep[u] - dep[anc]), mx_node(v, dep[v] - dep[anc])) << "\n";
    }
    return 0;
}