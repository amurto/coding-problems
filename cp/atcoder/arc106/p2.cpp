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

const int N = 2e5 + 5;
vector<int> g[N];

ll dfs(vector<ll> &a, vector<bool> &vis, int cur)
{
    vis[cur] = true;
    ll res = a[cur];
    for (int e : g[cur])
        if (!vis[e])
            res += dfs(a, vis, e);
    return res;
}

bool solve()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<ll> a(n + 1), b(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        a[i] -= b[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            if (dfs(a, vis, i) != 0)
                return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}