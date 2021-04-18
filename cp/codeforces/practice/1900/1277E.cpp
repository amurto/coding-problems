// https://codeforces.com/contest/1277/problem/E
// Two Fairs

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int dfs(vector<vector<int>> &g, vector<bool> &vis, int cur)
{
    int sz = 1;
    vis[cur] = true;
    for (int e : g[cur])
        if (!vis[e])
            sz += dfs(g, vis, e);
    return sz;
}

int cnt(vector<vector<int>> &g, int src, int invis, int n)
{
    vector<bool> vis(n + 1);
    vis[invis] = true;
    return n - dfs(g, vis, src) - 1;
}

ll solve()
{
    int n, m, a, b, u, v;
    cin >> n >> m >> a >> b;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    return cnt(g, a, b, n) * 1ll * cnt(g, b, a, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}