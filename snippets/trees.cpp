#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
// Entry and Exit time for Segment Tree
vector<int> vis1(N), vis2(N), dep(N);
vector<int> g[N];
int dfs(vector<int> &arr, int cur, int last, int t, int lvl)
{
    vis1[cur] = vis2[cur] = t;
    dep[cur] = lvl;
    if (g[cur].size() == 1 && g[cur][0] == last)
        return vis1[cur];
    int mx = vis1[cur];
    for (int e : g[cur])
        if (e != last)
            vis2[cur] = dfs(arr, e, cur, vis2[cur] + 1, lvl + 1);
    return vis2[cur];
}

// Diameter of tree
int diam_dfs(int cur, int last, int &diam)
{
    int mx = 0;
    for (int e : g[cur])
    {
        if (e != last)
        {
            dep[e] = dep[cur] + 1;
            int st = diam_dfs(e, cur, diam);
            diam = max(diam, mx + st);
            mx = max(mx, st);
        }
    }
    return mx + 1;
}

// second way of finding diameter
vector<int> g[N];
int dep[N], par[N];
int traverse(int cur, int last, int d)
{
    par[cur] = last;
    dep[cur] = d;
    int mx = cur;
    for (int e : g[cur])
    {
        if (e != last)
        {
            int v = traverse(e, cur, d + 1);
            if (dep[v] > dep[mx])
                mx = v;
        }
    }
    return mx;
}

int find_diam(int cur)
{
    // find farthest node from root
    int root = traverse(cur, -1, 1);
    // root is one end of diameter, find other end using same dfs
    int leaf = traverse(root, -1, 1);
    vector<int> nodes;
    while (leaf != -1)
    {
        nodes.pb(leaf);
        leaf = par[leaf];
    }
    int sz = nodes.size();
    return sz - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}