#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
int parent[N], cap[N];

class edge
{
public:
    int u, v, w;
    edge() {}
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const edge &other) const
    {
        return w < other.w;
    }
};

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
}

ll solve()
{
    int n, u, v, w;
    ll res = 0;
    cin >> n;
    init(n);
    vector<edge> edges;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        edges.pb(edge(u, v, w));
    }
    sort(edges.begin(), edges.end());
    for (edge e : edges)
    {
        res += 1ll * e.w * cap[root(e.u)] * cap[root(e.v)];
        merge(e.u, e.v);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}