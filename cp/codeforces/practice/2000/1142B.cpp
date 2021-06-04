// https://codeforces.com/contest/1142/problem/B
// Lynyrd Skynyrd

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void dfs(vector<vector<int>> &g, vector<int> &cycle, vector<int> &dep, vector<bool> &vis, int cur, int d, int n)
{
    vis[cur] = true;
    dep[d] = cur;
    if (d >= n)
        cycle[cur] = dep[d - n + 1];
    for (int e : g[cur])
        if (e != cur)
            dfs(g, cycle, dep, vis, e, d + 1, n);
}

void solve()
{
    int n, m, q, l, r;
    cin >> n >> m >> q;
    vector<int> p(n + 1), mask(n + 1), arr(m + 1), prev(n + 1), last(n + 1, -1), dep(m + 1), cycle(m + 1, -1);
    vector<bool> vis(m + 1);
    vector<vector<int>> g(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        mask[p[i]] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> arr[i];
        arr[i] = mask[arr[i]];
    }
    prev[1] = n;
    for (int i = 2; i <= n; i++)
        prev[i] = i - 1;
    for (int i = 1; i <= m; i++)
    {
        last[arr[i]] = i;
        if (last[prev[arr[i]]] != -1)
            g[last[prev[arr[i]]]].pb(i);
    }
    for (int i = 1; i <= m; i++)
        if (!vis[i])
            dfs(g, cycle, dep, vis, i, 1, n);
    for (int i = 1; i <= m; i++)
        cycle[i] = max(cycle[i - 1], cycle[i]);
    for (int t = 0; t < q; t++)
    {
        cin >> l >> r;
        (cycle[r] >= l) ? cout << 1 : cout << 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}