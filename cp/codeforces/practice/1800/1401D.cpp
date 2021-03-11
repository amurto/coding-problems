// https://codeforces.com/contest/1401/problem/D
// Maximum Distributed Tree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int dfs(vector<vector<int>> &g, vector<ll> &ct, int last, int cur, int n)
{
    if (g[cur].size() == 1 && g[cur][0] == last)
        return 1;
    int subtree = 0;
    for (int e : g[cur])
    {
        if (e == last)
            continue;
        int nd = dfs(g, ct, cur, e, n);
        subtree += nd;
        ct.pb(nd * 1ll * (n - nd));
    }
    return subtree + 1;
}

int solve()
{
    int n, u, v, m, res = 0;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> m;
    vector<int> p(m), val(n - 1, 1);
    vector<ll> ct;
    for (int i = 0; i < m; i++)
        cin >> p[i];
    sort(p.rbegin(), p.rend());
    int idx = 0;
    if (m > n - 1)
    {
        int g = m - (n - 1);
        idx = g;
        for (int i = 0; i < g; i++)
            p[g] = mul(p[g], p[i]);
    }
    for (int i = idx, j = 0; i < m; i++, j++)
        val[j] = p[i];
    dfs(g, ct, -1, 1, n);
    sort(ct.rbegin(), ct.rend());
    for (int i = 0; i < n - 1; i++)
        res = add(res, mul(val[i], ct[i] % MOD));
    return res;
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