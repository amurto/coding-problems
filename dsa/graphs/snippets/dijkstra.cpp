#include <bits/stdc++.h>
using namespace std;

// adjacency list
// g[u] = [[v,w]]
void dijkstra(vector<vector<pair<int, int>>> &g, int n, int source)
{
    const int inf = 1e9;
    vector<int> dis(n, inf);
    vector<bool> vis(n);
    dis[source] = 0;

    // min heap
    // {dis[v], v}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dis[source], source});
    
    while (!pq.empty())
    {
        pair<int, int> from = pq.top();
        pq.pop();
        if (vis[from.second])
            continue;
        vis[from.second] = true;
        for (pair<int, int> to : g[from.second])
        {
            if (!vis[to.first])
            {
                if (dis[from.second] + to.second < dis[to.first])
                    dis[to.first] = dis[from.second] + to.second;
                pq.push({dis[to.first], to.first});
            }
        }
    }
}
