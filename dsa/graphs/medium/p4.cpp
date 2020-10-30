// https://leetcode.com/problems/is-graph-bipartite/
// Is Graph Bipartite?

#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> vis(n);
    vector<int> parity(n);
    queue<int> Q;
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            int level = 0;
            Q.push(i);
            while (!Q.empty())
            {
                level ^= 1;
                int nodes = Q.size();
                while (nodes-- > 0)
                {
                    int cur = Q.front();
                    Q.pop();
                    if (!vis[cur])
                    {
                        vis[cur] = true;
                        parity[cur] = level;
                        for (int edge : graph[cur])
                            if (!vis[edge])
                                Q.push(edge);
                    }
                    else if (parity[cur] != level)
                        return false;
                }
            }
        }
    return true;
}

int main()
{
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    bool ans = isBipartite(graph);
    return 0;
}