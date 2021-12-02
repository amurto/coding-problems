#ifdef use_debug
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

    bool merge(int x, int y)
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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pii> edges(m);
    vector<int> deg(n + 1), res(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].first >> edges[i].second;
        deg[edges[i].first]++;
    }
    sort(edges.begin(), edges.end(), [&](pii &p1, pii &p2)
         { return p1.first > p2.first; });
    dsu ds(n);
    int c = 0;
    for (int i = 0, x = n; x > 1; x--)
    {
        c++;
        while (i < m && edges[i].first == x)
        {
            if (ds.merge(edges[i].first, edges[i].second))
                c--;
            i++;
        }
        res[x - 1] = c;
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}