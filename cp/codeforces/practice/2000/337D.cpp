// https://codeforces.com/contest/337/problem/D
// Book of Evil

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
vector<int> g[N];
int p[N], sub[N], dis[N];

int inc(int x)
{
    if (x == 0)
        return 0;
    return x + 1;
}

int dfs(int cur, int last)
{
    sub[cur] = 0;
    for (int e : g[cur])
        if (e != last)
            sub[cur] = max(sub[cur], dfs(e, cur));
    if (sub[cur] > 0)
        return sub[cur] + 1;
    return p[cur];
}

void reroot(int cur, int last, int mx)
{
    dis[cur] = max(sub[cur], mx);
    vector<int> tmp;
    for (int e : g[cur])
    {
        if (e == last)
            tmp.pb(mx);
        else
            tmp.pb(max(p[e], inc(sub[e])));
    }
    int sz = g[cur].size();
    vector<int> suf(sz + 1);
    for (int i = sz - 1; i >= 0; i--)
        suf[i] = max(tmp[i], suf[i + 1]);
    int pre = 0;
    for (int i = 0; i < g[cur].size(); i++)
    {
        int e = g[cur][i];
        if (e != last)
            reroot(e, cur, max(p[cur], inc(max(pre, suf[i + 1]))));
        pre = max(pre, tmp[i]);
    }
}

int solve()
{
    int n, m, u, v, d;
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++)
        p[i] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> u;
        p[u] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 1);
    reroot(1, 1, 0);
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += (dis[i] <= d);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}