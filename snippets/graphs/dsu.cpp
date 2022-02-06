#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int parent[N], cap[N];
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        cap[i] = 1;
    }
}

int root(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = root(parent[x]);
}

void merge(int x, int y)
{
    int rx = root(x), ry = root(y);
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
    init(n);
    return 0;
}

// Struct DSU
struct dsu
{
    int n;
    vector<int> parent, cap;
    dsu(int l)
    {
        n = l;
        parent.resize(n + 1);
        cap.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            cap[i] = 1;
        }
    }

    int root(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = root(parent[x]);
    }

    bool merge_nodes(int x, int y)
    {
        int rx = root(x), ry = root(y);
        if (rx == ry)
            return false;
        // by size (capacity)
        if (cap[rx] < cap[ry])
            swap(rx, ry);
        cap[rx] += cap[ry];
        parent[ry] = parent[rx];
        return true;
    }
};
