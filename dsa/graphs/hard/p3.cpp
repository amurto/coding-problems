// https://acm.timus.ru/problem.aspx?space=1&num=1671
// Anansi's Cobweb
// dsu

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

bool merge(vector<int> &parent, vector<int> &size, int x, int y)
{
    int rx = root(parent, x), ry = root(parent, y);
    if (rx == ry)
        return false;
    
    // by size
    if (size[ry] < size[ry])
        swap(rx, ry);
    size[rx] += size[ry];
    parent[ry] = parent[rx];
    return true;
}

int main()
{
    int n, m, u, v, q, idx;
    cin >> n >> m;
    int pieces = n;
    vector<int> parent(n + 1), size(n + 1, 1);
    vector<bool> unused(m + 1, false);
    init(parent, n);
    vector<pair<int, int>> edge;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        edge.push_back({u, v});
    }
    cin >> q;
    vector<int> Q(q);
    for (int i = 0; i < q; i++)
    {
        cin >> Q[i];
        Q[i]--;
        unused[Q[i]] = true;
    }
    for (int i = 0; i < m; i++)
    {
        if (unused[i])
            continue;
        if (merge(parent, size, edge[i].first, edge[i].second))
            pieces--;
    }
    vector<int> res;
    for (int i = q - 1; i >= 0; i--)
    {
        res.push_back(pieces);
        if (merge(parent, size, edge[Q[i]].first, edge[Q[i]].second))
            pieces--;
    }
    cout << res[res.size() - 1];
    for (int i = res.size() - 2; i >= 0; i--)
        cout << " " << res[i];
    return 0;
}