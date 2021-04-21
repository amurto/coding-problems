// https://codeforces.com/contest/1092/problem/F
// Tree with Maximum Cost

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

const int N = 2e5 + 5;
vector<int> g[N];
ll cost[N], subtree[N], subsum[N];

pii dfs1(int cur, int last)
{
    ll sum_cost = 0, dist_cost = 0;
    for (int e : g[cur])
    {
        if (e != last)
        {
            pii p = dfs1(e, cur);
            sum_cost += p.first;
            dist_cost += p.second;
        }
    }
    subsum[cur] = sum_cost + cost[cur];
    subtree[cur] = dist_cost + sum_cost;
    return {sum_cost + cost[cur], subtree[cur]};
}

ll dfs2(int cur, int last, ll par_sum, ll par_tree)
{
    ll res = subtree[cur] + par_tree;
    for (int e : g[cur])
        if (e != last)
            res = max(res, dfs2(e, cur, subsum[cur] - subsum[e] + par_sum, subtree[cur] - subtree[e] - 2 * subsum[e] + subsum[cur] + par_tree + par_sum));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(1, -1);
    cout << dfs2(1, -1, 0ll, 0ll) << "\n";
    return 0;
}