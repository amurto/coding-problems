// https://codeforces.com/contest/466/problem/E
// Information Graph

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 1e5 + 5, LGN = 19;
vector<pii> g[N];
int up[N][LGN + 1], mx[N][LGN + 1], tin[N], tout[N], dep[N], vis[N], timer = 0;
pii doc[N];

void dfs(int cur, int last, int edge_time, int d)
{
    tin[cur] = ++timer;
    dep[cur] = d;
    up[cur][0] = last;
    mx[cur][0] = edge_time;
    for (int i = 1; i <= LGN; i++)
    {
        up[cur][i] = up[up[cur][i - 1]][i - 1];
        mx[cur][i] = max(mx[cur][i - 1], mx[up[cur][i - 1]][i - 1]);
    }
    for (pii e : g[cur])
        if (e.first != last)
            dfs(e.first, cur, e.second, d + 1);
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

int mx_edge(int u, int k)
{
    if (k == 0)
        return 0;
    int mxe = 0;
    for (int i = LGN; i >= 0; i--)
    {
        if ((1 << i) <= k)
        {
            mxe = max(mxe, mx[u][i]);
            u = up[u][i];
            k -= (1 << i);
        }
    }
    return mxe;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, t, x, y;
    cin >> n >> m;
    vector<bool> root(n + 1, true);
    vector<pii> query;
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        doc[i] = {0, 0};
    }
    for (int i = 1, p = 1; i <= m; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x >> y;
            root[x] = false;
            vis[x] = i;
            g[x].pb({y, i});
            g[y].pb({x, i});
        }
        else if (t == 2)
        {
            cin >> x;
            doc[p] = {x, i};
            p++;
        }
        else
        {
            cin >> x >> y;
            query.pb({x, y});
        }
    }
    for (int i = 1; i <= n; i++)
        if (root[i])
            dfs(i, i, 0, 0);
    for (pii q : query)
    {
        int d = q.second;
        if (is_ancestor(q.first, doc[d].first) && mx_edge(doc[d].first, dep[doc[d].first] - dep[q.first]) < doc[d].second)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}