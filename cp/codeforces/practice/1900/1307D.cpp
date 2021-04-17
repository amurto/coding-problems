// https://codeforces.com/contest/1307/problem/D
// Cow and Fields

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e6 + 5;

void bfs(vector<vector<int>> &g, vector<int> &dis, int src, int n)
{
    vector<bool> vis(n + 1);
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;
    int d = 1;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            int cur = q.front();
            q.pop();
            for (int e : g[cur])
            {
                if (!vis[e])
                {
                    q.push(e);
                    vis[e] = true;
                    dis[e] = d;
                }
            }
        }
        d++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, u, v;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1);
    vector<int> node(k), dis(n + 1, inf), st(n + 1, inf), suf(k);
    for (int i = 0; i < k; i++)
        cin >> node[i];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    bfs(g, dis, n, n);
    bfs(g, st, 1, n);
    int mxd = dis[1];
    sort(node.begin(), node.end(), [&](int &i1, int &i2) {
        if (dis[i1] == dis[i2])
            return st[i1] < st[i2];
        return dis[i1] > dis[i2];
    });
    for (int i = 0; i < k; i++)
        suf[i] = dis[node[i]];
    for (int i = k - 2; i >= 0; i--)
        suf[i] = max(suf[i], suf[i + 1]);
    int res = 0;
    for (int i = 0; i < k - 1; i++)
        res = max(res, st[node[i]] + 1 + suf[i + 1]);
    cout << min(res, mxd) << "\n";
    return 0;
}