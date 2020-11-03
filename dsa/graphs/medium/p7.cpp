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

    // djikstra without visited and distance memo
    for (vector<int> edge : flights)
        g[edge[0]].push_back({edge[1], edge[2]});

    // st[u] = minimum stops to reach u
    vector<int> st(n, 1e9);

    // min heap
    // {dis[u], {u, stops_required}}
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({0, {src, 0}});
    while (!pq.empty())
    {
        piii top = pq.top();
        pq.pop();
        int dis = top.first, from = top.second.first, stops = top.second.second;

        // return dist[dst] if dst is found
        if (from == dst)
            return dis;
        
        // atmost k stops
        // if min_stops <= stops, skip adding vertices
        if (st[from] <= stops || stops > K)
            continue;
        for (pair<int, int> to : g[from])
            pq.push({dis + to.second, {to.first, stops + 1}});
    }
    return -1;
}

int main()
{
    vector<vector<int>> edges = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int n = 3, src = 0, dst = 2, k = 0;
    cout << findCheapestPrice(n, edges, src, dst, k) << "\n";
    return 0;
}