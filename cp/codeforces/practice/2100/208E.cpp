// https://codeforces.com/contest/208/problem/E
// Blood Cousins

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5, LGN = 19;
vector<int> g[N], st[N];
int up[N][LGN + 1], tin[N], tout[N], dep[N], vis[N], timer = 0;

void dfs(int cur, int last, int d)
{
    vis[cur] = 1;
    tin[cur] = ++timer;
    dep[cur] = d;
    st[d].pb(tin[cur]);
    up[cur][0] = last;
    for (int i = 1; i <= LGN; i++)
        up[cur][i] = up[up[cur][i - 1]][i - 1];
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
    int n, m, v, p;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        cin >> p;
        if (p > 0)
        {
            g[p].pb(i);
            g[i].pb(p);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, i, 0);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> v >> p;
        int k = k_ancestor(v, p);
        if (k == -1)
            cout << 0 << " ";
        else
        {
            int d = dep[v];
            int lb = lower_bound(st[d].begin(), st[d].end(), tin[k]) - st[d].begin();
            int rb = upper_bound(st[d].begin(), st[d].end(), tout[k]) - st[d].begin();
            cout << rb - lb - 1 << " ";
        }
    }
    return 0;
}