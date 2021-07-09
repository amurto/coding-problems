#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
vector<int> g[N];
int src[N], des[N], col[N];

void dfs(vector<bool> &vis, int cur, int p)
{
    vis[cur] = true;
    col[cur] = p;
    for (int e : g[cur])
        if (!vis[e])
            dfs(vis, e, p ^ 1);
}

bool solve()
{
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= n; i++)
        cin >> src[i];
    for (int i = 1; i <= n; i++)
        cin >> des[i];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<bool> vis(n + 1);
    dfs(vis, 1, 0);
    vector<ll> cnt(2);
    bool bipartite = true;
    for (int i = 1; i <= n; i++)
    {
        cnt[col[i]] += 1ll * (des[i] - src[i]);
        for (int e : g[i])
            if (col[i] == col[e])
                bipartite = false;
    }
    if (bipartite)
        return cnt[0] == cnt[1];
    return (cnt[0] + cnt[1]) % 2 == 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}