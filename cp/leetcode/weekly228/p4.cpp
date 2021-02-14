#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int minTrioDegree(int n, vector<vector<int>> &edges)
{
    int inf = 1e7;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    vector<vector<int>> g(n + 1);
    for (vector<int> e : edges)
    {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
        adj[e[0]][e[1]] = adj[e[1]][e[0]] = 1;
    }
    int res = inf;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < g[i].size(); j++)
            for (int k = j + 1; k < g[i].size(); k++)
                if (adj[g[i][j]][g[i][k]] == 1)
                    res = min(res, (int)g[i].size() + (int)g[g[i][j]].size() + (int)g[g[i][k]].size() - 6);
    return (res >= inf) ? -1 : res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        vector<int> e;
        e.pb(u);
        e.pb(v);
        edges.pb(e);
    }
    cout << minTrioDegree(n, edges) << "\n";
    return 0;
}