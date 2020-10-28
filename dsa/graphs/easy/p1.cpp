// Structure

#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int n;
    vector<vector<pair<int, int>>> adjlist;
    Graph(int N)
    {
        n = N;
        adjlist.resize(N);
    }

    // source -> destination with weight
    void addEdge(int src, int des, int wt)
    {
        adjlist[src].push_back({des, wt});
    }

    // display edge
    // source -> destination
    void display()
    {
        for (int i = 0; i < adjlist.size(); i++)
            for (int j = 0; j < adjlist[i].size(); j++)
                cout << i << " -> " << adjlist[i][j].first << "\n";
    }

    // depth first search
    void explore(int cur, vector<bool> &vis, vector<int> &comp)
    {
        vis[cur] = true;
        comp.push_back(cur);
        for (pair<int, int> edge : adjlist[cur])
            if (!vis[edge.first])
                explore(edge.first, vis, comp);
    }

    // returns all nodes connected to source
    vector<int> dfs(int src)
    {
        vector<bool> vis(n);
        vector<int> comp;
        explore(src, vis, comp);
        return comp;
    }

    // Check if path from src -> des exists
    bool hasPath(int src, int des)
    {
        vector<bool> vis(n);
        vector<int> comp;
        explore(src, vis, comp);
        if (vis[des])
            return true;
        return false;
    }

    void dfs_backtrack(string soFar, int cur, int des, vector<bool> &vis, vector<string> &paths)
    {
        if (cur == des)
        {
            soFar += to_string(des);
            paths.push_back(soFar);
            return;
        }
        vis[cur] = true;
        for (pair<int, int> edge : adjlist[cur])
            if (!vis[edge.first])
                dfs_backtrack(soFar + to_string(cur), edge.first, des, vis, paths);
        vis[cur] = false;
    }

    // return all distinct paths possible from src -> des
    vector<string> allPaths(int src, int des)
    {
        vector<bool> vis(n);
        vector<string> paths;
        dfs_backtrack("", src, des, vis, paths);
        return paths;
    }

    // returns all connected components
    vector<vector<int>> getConnectedComps()
    {
        vector<vector<int>> res;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vector<int> comp;
                explore(i, vis, comp);
                if (!comp.empty())
                    res.push_back(comp);
            }
        }
        return res;
    }

    // check if entire graph is connected
    bool isConnected()
    {
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vector<int> comp;
                explore(i, vis, comp);
                if (comp.size() == n)
                    return true;
                else if (comp.size() > 0)
                    return false;
            }
        }
        return false;
    }
};

int main()
{
    int n, e, s, d, w;
    cin >> n;
    Graph G = Graph(n);
    cin >> e;
    while (e-- > 0)
    {
        cin >> s >> d >> w;
        G.addEdge(s, d, w);
        G.addEdge(d, s, w);
    }
    if (G.isConnected())
        cout << "true \n";
    else
        cout << "false \n";
    return 0;
}

// cout << "[";
// if (!cc.empty()) {
//     cout << "[";
//     cout << cc[0][0];
//     for (int i = 1; i < cc[0].size(); i++)
//         cout << ", " << cc[0][i];
//     cout << "]";
// }
// for (int c=1; c < cc.size(); c++)
// {
//     cout << ", [";
//     cout << cc[c][0];
//     for (int i = 1; i < cc[c].size(); i++)
//         cout << ", " << cc[c][i];
//     cout << "]";
// }
// cout << "]";