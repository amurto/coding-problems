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

    // by rank
    // if (cap[rx] < cap[ry])
    //     swap(rx, ry);
    // parent[ry] = rx;
    // if (cap[rx] == cap[ry])
    //     cap[rx]++;
}

int main()
{
    int n;
    cin >> n;
    // fill cap with 0 for rank
    vector<int> parent(n + 1), cap(n + 1, 1);
    init(parent, n);
    return 0;
}