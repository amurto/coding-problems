// https://codeforces.com/contest/1388/problem/C
// Uncle Bogdan and Country Happiness

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll satisfy(ll pp, ll hh, bool &sat)
{
    if ((pp + hh) & 1)
    {
        sat = false;
        return -1;
    }
    ll x = (pp + hh) / 2;
    ll y = pp - x;
    if (x < 0 || y < 0)
    {
        sat = false;
        return -1;
    }
    return x;
}

ll dfs(vector<vector<int>> &g, vector<ll> &h, vector<ll> &p, vector<ll> &gd, int cur, int last, bool &sat)
{
    if (g[cur].size() == 1 && g[cur][0] == last)
    {
        gd[cur] = satisfy(p[cur], h[cur], sat);
        return p[cur];
    }
    ll pp = p[cur];
    for (int e : g[cur])
    {
        if (e == last)
            continue;
        pp += dfs(g, h, p, gd, e, cur, sat);
    }
    gd[cur] = satisfy(pp, h[cur], sat);
    ll sum = 0;
    for (int e : g[cur])
    {
        if (e == last)
            continue;
        sum += gd[e];
    }
    if (sum > gd[cur])
        sat = false;
    return pp;
}

bool solve()
{
    int n, m, u, v;
    cin >> n >> m;
    bool sat = true;
    vector<vector<int>> g(n + 1);
    vector<ll> p(n + 1), gd(n + 1), h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(g, h, p, gd, 1, -1, sat);
    return sat;
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