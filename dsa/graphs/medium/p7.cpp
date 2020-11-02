// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Cheapest Flights Within K Stops

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
#define pb push_back

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    if (src == dst)
        return 0;
    // create a graph
    vector<vector<pair<int, int>>> g(n);
    for (vector<int> edge : flights)
    {
        g[edge[0]].push_back({edge[1], edge[2]});
        g[edge[1]].push_back({edge[0], edge[2]});
    }
    const int inf = 1e9;
    vector<bool> vis(n);
    vector<int> dis(n, inf);
    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dis[src], src});
    while (!pq.empty() && K >= 0)
    {
        int size = pq.size();
        while (size-- > 0)
        {
            pair<int, int> from = pq.top();
            pq.pop();
            if (vis[from.second])
                continue;
            vis[from.second] = true;
            for (pair<int, int> to : g[from.second])
                if (!vis[to.first])
                {
                    dis[to.first] = min(dis[to.first], dis[from.second] + to.second);
                    pq.push({dis[to.first], to.first});
                }
        }
        K--;
    }
    return dis[dst] == inf ? -1 : dis[dst];
}

int main()
{
    vector<vector<int>> edges = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int n = 3, src = 0, dst = 2, k = 0;
    cout << findCheapestPrice(n, edges, src, dst, k) << "\n";
    return 0;
}