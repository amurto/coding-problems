// https://codeforces.com/contest/1304/problem/E
// 1-Trees and Queries

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5, LGN = 19;
vector<int> g[N];
int up[N][LGN + 1], tin[N], tout[N], dep[N], timer = 0;

void dfs(int cur, int last, int d)
{
    tin[cur] = ++timer;
    dep[cur] = d;
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

int dis(int u, int v)
{
    int anc = lca(u, v);
    return dep[u] + dep[v] - 2 * dep[anc];
}

bool solve()
{
    int x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;
    vector<int> seq;
    seq.pb(dis(a, b));
    for (int j = 0; j < 2; j++)
    {
        seq.pb(dis(a, x) + 1 + dis(b, y));
        swap(x, y);
    }
    for (int e : seq)
        if (e <= k && (e % 2) == (k % 2))
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, x, y, a, b, k;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, 1, 0);
    cin >> q;
    for (int i = 0; i < q; i++)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}