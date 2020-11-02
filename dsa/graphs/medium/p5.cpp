// https://leetcode.com/problems/network-delay-time/
// Network Delay Time

#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int N, int K)
{
    // create a graph
    vector<vector<pair<int, int>>> g(N + 1);

    // adjacency list
    // g[u] = [[v,w]]
    for (vector<int> data : times)
        g[data[0]].push_back({data[1], data[2]});

    // dijkstra
    const int inf = 1e9;
    vector<int> dis(N + 1, inf);
    vector<bool> vis(N + 1);
    dis[K] = 0;

    // min heap
    // {dis[v], v}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dis[K], K});
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

    // return the farthest distance
    int time = 0;
    for (int i = 1; i <= N; i++)
        time = max(time, dis[i]);

    // farthest distance == inf then node cannot be reached
    return time == inf ? -1 : time;
}

int main()
{
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int N = 4, K = 2;
    cout << networkDelayTime(times, N, K) << "\n";
    return 0;
}