// https://codeforces.com/contest/839/problem/C
// Journey

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
vector<int> g[N];

double dfs(vector<bool> &vis, int cur, int len, double d)
{
    if (cur != 1 && g[cur].size() == 1)
        return d * len;
    double res = 0;
    int sz = g[cur].size();
    if (cur != 1)
        sz--;
    vis[cur] = true;
    for (int e : g[cur])
        if (!vis[e])
            res += dfs(vis, e, len + 1, d / (sz * 1.0));
    return res;
}

double solve()
{
    int n, u, v;
    cin >> n;
    vector<bool> vis(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    return dfs(vis, 1, 0, 1.0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(9) << solve() << "\n";
    return 0;
}