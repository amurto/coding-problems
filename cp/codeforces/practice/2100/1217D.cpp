// https://codeforces.com/contest/1217/problem/D
// Coloring Edges

#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 5005;
int adj[N][N];
vector<int> g[N];

void dfs(vector<int> &vis, int cur, int last)
{
    if (vis[cur] > 0)
    {
        if (vis[cur] == 1)
            adj[last][cur] = 2;
        return;
    }
    vis[cur] = 1;
    for (int e : g[cur])
        dfs(vis, e, cur);
    vis[cur] = 2;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m);
    vector<int> vis(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i];
        g[u[i]].pb(v[i]);
        adj[u[i]][v[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(vis, i, i);
    vector<int> cols;
    for (int i = 0; i < m; i++)
        cols.pb(adj[u[i]][v[i]]);
    int k = *max_element(cols.begin(), cols.end());
    cout << k << "\n";
    for (int c : cols)
        cout << c << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}