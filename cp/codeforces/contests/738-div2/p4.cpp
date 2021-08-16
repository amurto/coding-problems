#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
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
    int n, m1, m2, u, v;
    cin >> n >> m1 >> m2;
    dsu d1(n), d2(n);
    for (int i = 0; i < m1; i++)
    {
        cin >> u >> v;
        d1.merge(u, v);
    }
    for (int i = 0; i < m2; i++)
    {
        cin >> u >> v;
        d2.merge(u, v);
    }
    vector<pii> edges;
    for (int j = 2; j <= n; j++)
    {
        int ri1 = d1.root(1), rj1 = d1.root(j), ri2 = d2.root(1), rj2 = d2.root(j);
        if (ri1 != rj1 && ri2 != rj2)
        {
            edges.pb({1, j});
            d1.merge(1, j);
            d2.merge(1, j);
        }
    }
    vector<int> rts1, rts2;
    int ri1 = d1.root(1), ri2 = d2.root(1);
    for (int i = 2; i <= n; i++)
        if (d1.root(i) == i && i != ri1)
            rts1.pb(i);
    for (int i = 2; i <= n; i++)
        if (d2.root(i) == i && i != ri2)
            rts2.pb(i);
    int sz = min((int)rts1.size(), (int)rts2.size());
    for (int i = 0; i < sz; i++)
    {
        d1.merge(rts1[i], rts2[i]);
        d2.merge(rts1[i], rts2[i]);
        edges.pb({rts1[i], rts2[i]});
    }
    cout << edges.size() << "\n";
    for (pii e : edges)
        cout << e.first << " " << e.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}