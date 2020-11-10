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
    int n;
    cin >> n;
    vector<int> parent(n + 1), size(n + 1, 1);
    init(parent, n);
    return 0;
}