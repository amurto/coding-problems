// https://codeforces.com/contest/191/problem/C
// Fools and Roads

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 1e5 + 5, LGN = 19;
vector<pii> g[N];
int up[N][LGN + 1], tin[N], tout[N], dep[N], val[N], timer = 0;

void dfs(int cur, int last, int d)
{
    tin[cur] = ++timer;
    dep[cur] = d;
    up[cur][0] = last;
    for (int i = 1; i <= LGN; i++)
        up[cur][i] = up[up[cur][i - 1]][i - 1];
    for (pii e : g[cur])
        if (e.first != last)
            dfs(e.first, cur, d + 1);
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

int traverse(vector<int> &road, int cur, int last)
{
    for (pii e : g[cur])
    {
        if (e.first != last)
        {
            int v = traverse(road, e.first, cur);
            road[e.second] = v;
            val[cur] += v;
        }
    }
    return val[cur];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, u, v, k;
    cin >> n;
    for (int i = 1; i <= n; i++)
        val[i] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    dfs(1, 1, 0);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> u >> v;
        if (u != v)
        {
            val[u]++;
            val[v]++;
            val[lca(u, v)] -= 2;
        }
    }
    vector<int> road(n - 1);
    traverse(road, 1, 1);
    for (int r : road)
        cout << r << " ";
    return 0;
}