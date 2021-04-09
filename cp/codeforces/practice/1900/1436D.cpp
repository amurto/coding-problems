// https://codeforces.com/contest/1436/problem/D
// Bandit in a City

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll sum_dfs(vector<vector<int>> &g, vector<ll> &a, vector<ll> &sum, int cur, int last)
{
    sum[cur] = a[cur];
    for (int e : g[cur])
        if (e != last)
            sum[cur] += sum_dfs(g, a, sum, e, cur);
    return sum[cur];
}

pair<ll, ll> mx_dfs(vector<vector<int>> &g, vector<ll> &sum, int cur, int last)
{
    if (g[cur].size() == 1 && g[cur].back() == last)
        return {sum[cur], 1};
    ll leaf = 0, mx = 0;
    for (int e : g[cur])
    {
        if (e == last)
            continue;
        pair<ll, ll> ret = mx_dfs(g, sum, e, cur);
        leaf += ret.second;
        mx = max(mx, ret.first);
    }
    mx = max(mx, (sum[cur] + leaf - 1) / leaf);
    return {mx, leaf};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<ll> a(n + 1), sum(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> p;
        g[p].pb(i);
        g[i].pb(p);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sum_dfs(g, a, sum, 1, -1);
    pair<ll, ll> res = mx_dfs(g, sum, 1, -1);
    cout << res.first << "\n";
    return 0;
}