#include <bits/stdc++.h>
using namespace std;

void init(vector<int> &parent, int n)
{
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int root(vector<int> &parent, int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = root(parent, parent[x]);
}

void dsunion(vector<int> &parent, vector<int> &cap, int x, int y)
{
    int rx = root(parent, x), ry = root(parent, y);
    if (rx == ry)
        return;

    // by size (capacity)
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1), cap(n + 1);
    init(parent, n);
    vector<pair<int, pair<int, int>>> edge(m);
    for (int i = 0; i < m; i++)
        cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
    sort(edge.begin(), edge.end());
    int cost = 0;
    for (pair<int, pair<int, int>> e : edge)
    {
        if (root(parent, e.second.first) == root(parent, e.second.second))
            continue;
        dsunion(parent, cap, e.second.first, e.second.second);
        cost += e.first;
    }
    cout << cost << "\n";
    return 0;
}