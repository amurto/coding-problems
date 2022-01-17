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
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<bool> res(q);
    vector<int> u(m + q), v(m + q), c(m + q), ids(m + q);
    for (int i = 0; i < m + q; i++)
        cin >> u[i] >> v[i] >> c[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return c[i1] < c[i2]; });
    dsu ds(n);
    for (int id : ids)
    {
        int a = u[id], b = v[id];
        int ra = ds.root(a), rb = ds.root(b);
        if (id >= m && ra != rb)
            res[id - m] = true;
        else
            ds.merge(a, b);
    }
    for (int i = 0; i < q; i++)
        res[i] ? cout << "Yes\n" : cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}