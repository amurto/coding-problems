// https://codeforces.com/contest/1337/problem/C
// Linova and Kingdom

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int dfs(vector<vector<int>> &g, vector<int> &parent, vector<int> &dis, vector<int> &st, int cur, int len)
{
    dis[cur] = len;
    int sub = 0;
    for (int e : g[cur])
    {
        if (e == parent[cur])
            continue;
        parent[e] = cur;
        sub += dfs(g, parent, dis, st, e, len + 1);
    }
    st[cur] = sub;
    return sub + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, u, v;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    vector<int> parent(n + 1), dis(n + 1), st(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(g, parent, dis, st, 1, 0);
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
        pq.push(dis[i] - st[i]);
    ll res = 0;
    while (k-- > 0)
    {
        res += pq.top();
        pq.pop();
    }
    cout << res << "\n";
    return 0;
}