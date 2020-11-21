#include <bits/stdc++.h>
using namespace std;

// adjacency list
// g[u] = [[v,w]]
int prims(vector<vector<pair<int, int>>> &g, int n, int source)
{
    int cost = 0;
    vector<bool> vis(n + 1);

    // min heap
    // {dis[v], v}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        pair<int, int> from = pq.top();
        pq.pop();
        if (vis[from.second])
            continue;
        cost += from.first;
        vis[from.second] = true;
        for (pair<int, int> to : g[from.second])
        {
            if (!vis[to.first])
                pq.push({to.second, to.first});
        }
    }
    return cost;
}

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    cout << prims(g, n, 1) << "\n";
    return 0;
}