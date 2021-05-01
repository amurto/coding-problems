#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 2e5 + 5, LGN = 19;
vector<int> g[N];
int up[N][LGN + 1], tin[N], tout[N], dep[N], sub[N], timer = 0;
bool sp[N];

void init(int n)
{
    timer = 0;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        sp[i] = false;
    }
}

int dfs(int cur, int last, int d)
{
    sub[cur] = 0;
    if (sp[cur])
        sub[cur] = cur;
    tin[cur] = ++timer;
    dep[cur] = d;
    up[cur][0] = last;
    for (int i = 1; i <= LGN; i++)
        up[cur][i] = up[up[cur][i - 1]][i - 1];
    for (int e : g[cur])
        if (e != last)
            sub[cur] = max(sub[cur], dfs(e, cur, d + 1));
    tout[cur] = timer;
    return sub[cur];
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

int bs(int b)
{
    if (sub[b] > 0)
        return b;
    for (int i = LGN; i >= 0; i--)
        if (sub[up[b][i]] == 0)
            b = up[b][i];
    return up[b][0];
}
void solve()
{
    int n, k, a, u, v;
    cin >> n >> k >> a;
    init(n);
    vector<int> f(k), tmp(k);
    vector<pii> res;
    for (int i = 0; i < k; i++)
    {
        cin >> f[i];
        sp[f[i]] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(a, a, 0);
    for (int b = 1; b <= n; b++)
    {
        if (a == b)
            res.pb({0, f[0]});
        else
        {
            int p = bs(b);
            res.pb({2 * dep[p] - dep[b], sub[p]});
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i].first << " ";
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << res[i].second << " ";
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