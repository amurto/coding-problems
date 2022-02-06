#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct dsu
{
    int n;
    vector<int> parent, cap;
    dsu(int l)
    {
        n = l;
        parent.resize(n + 1);
        cap.resize(n + 1);
        for (int i = 0; i <= n; i++)
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

bool solve()
{
    int n, q;
    cin >> n >> q;
    dsu ds(n);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        ds.merge_nodes(l - 1, r);
    }
    return ds.root(0) == ds.root(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}