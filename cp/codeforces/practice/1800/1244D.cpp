// https://codeforces.com/contest/1244/problem/D
// Paint the Tree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int idx(int i1, int i2)
{
    for (int i = 0; i < 3; i++)
        if (i1 != i && i2 != i)
            return i;
    return 2;
}

ll dfs(vector<vector<int>> &g, vector<vector<int>> &c, vector<int> &op, int cur, int f, int s)
{
    op[cur] = idx(op[f], op[s]);
    ll sum = c[op[cur]][cur];
    for (int e : g[cur])
        if (e != f && e != s)
            sum += dfs(g, c, op, e, cur, f);
    return sum;
}

ll op(vector<vector<int>> &c, vector<vector<int>> &opt, vector<int> &seq, int p, int n)
{
    ll sum = 0;
    for (int i = 2; i < n; i++)
        opt[p][seq[i]] = idx(opt[p][seq[i - 2]], opt[p][seq[i - 1]]);
    for (int s : seq)
        sum += 1ll * c[opt[p][s]][s];
    return sum;
}

void solve()
{
    int n, u, v;
    cin >> n;
    vector<vector<int>> c(3, vector<int>(n + 1)), opt(6, vector<int>(n + 1));
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int src = 0;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() > 2)
        {
            cout << "-1\n";
            return;
        }
        if (g[i].size() == 1)
            src = i;
    }
    ll cst = 1e18 + 7, res = 0;
    int d = g[1][0];
    vector<pair<int, int>> col = {{0, 1}, {1, 0}, {0, 2}, {2, 0}, {1, 2}, {2, 1}};
    for (int p = 0; p < 6; p++)
    {
        opt[p][1] = col[p].first;
        opt[p][d] = col[p].second;
        ll sum = 1ll * c[opt[p][1]][1] + 1ll * c[opt[p][d]][d];
        for (int e : g[1])
            if (e != d)
                sum += dfs(g, c, opt[p], e, 1, d);
        for (int e : g[d])
            if (e != 1)
                sum += dfs(g, c, opt[p], e, d, 1);
        if (sum < cst)
        {
            cst = sum;
            res = p;
        }
    }
    cout << cst << "\n";
    for (int i = 1; i <= n; i++)
        cout << opt[res][i] + 1 << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}