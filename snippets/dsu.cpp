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

void dsunion(vector<int> &parent, vector<int> &size, int x, int y)
{
    int rx = root(parent, x), ry = root(parent, y);
    if (rx == ry)
        return;

    // by size
    if (size[rx] < size[ry])
        swap(rx, ry);
    size[rx] += size[ry];
    parent[ry] = parent[rx];

    // by rank
    // if (size[rx] < size[ry])
    //     swap(rx, ry);
    // parent[ry] = rx;
    // if (size[rx] == size[ry])
    //     size[rx]++;
}

int main()
{
    int n;
    cin >> n;
    // fill size with 0 for rank
    vector<int> parent(n + 1), size(n + 1, 1);
    init(parent, n);
    return 0;
}