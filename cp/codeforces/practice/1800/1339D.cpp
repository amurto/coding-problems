// https://codeforces.com/contest/1339/problem/D
// Edge Weight Assignment

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int dfs(vector<vector<int>> &g, int cur, int last, int p)
{
    if (g[cur].size() == 1 && g[cur][0] == last)
        return 1;
    for (int e : g[cur])
        if (e != last && dfs(g, e, cur, p ^ 1) != p)
            return 3;
    return p ^ 1;
}

void solve()
{
    int n, u, v, leaf = 0;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> par(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == 1)
        {
            par[g[i][0]]++;
            leaf = i;
        }
    }
    int mx = n - 1;
    for (int i = 1; i <= n; i++)
        if (par[i] > 0)
            mx -= par[i] - 1;
    int mn = dfs(g, leaf, -1, 0);
    if (mn < 3)
        mn = 1;
    cout << mn << " " << mx << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}