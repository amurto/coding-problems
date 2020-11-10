// https://acm.timus.ru/problem.aspx?space=1&num=1671
// Anansi's Cobweb

#include <bits/stdc++.h>
using namespace std;

void init(vector<int> &parent, int n)
{
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int root(vector<int> &parent, int x)
{
    while (parent[x] != x)
        x = parent[parent[x]];
    return x;
}

bool find(vector<int> &parent, int x, int y)
{
    return (root(parent, x) == root(parent, y));
}

void dsunion(vector<int> &parent, vector<int> &size, int x, int y)
{
    int rx = root(parent, x), ry = root(parent, y);
    if (size[ry] < size[ry])
        swap(rx, ry);
    size[rx] += size[ry];
    parent[ry] = parent[rx];
}

int main()
{
    int n, m, u, v, q, idx;
    cin >> n >> m;
    int pieces = n;
    vector<int> parent(n + 1), size(n + 1, 1);
    vector<bool> add(m + 1, false);
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
        add[Q[i]] = true;
    }
    for (int i = 0; i < m; i++)
    {
        if (!add[i]) {
            if (!find(parent, edge[i].first, edge[i].second))
                pieces--;
            parent[root(parent, edge[i].first)] = parent[root(parent, edge[i].second)];
        }
    }
    vector<int> res;
    for (int i = q - 1; i >= 0; i--)
    {
        res.push_back(pieces);
        if (!find(parent, edge[Q[i]].first, edge[Q[i]].second))
        {
            pieces--;
            dsunion(parent, size, edge[i].first, edge[i].second);
        }
    }
    for (int i=res.size()-1; i>=0; i--)
        cout << res[i] << " ";
    cout << "\n";
    return 0;
}