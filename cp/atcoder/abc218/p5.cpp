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

ll solve()
{
    int n, m;
    cin >> n >> m;
    init(n);
    ll res = 0;
    vector<pii> edges(m);
    vector<ll> cost(m);
    vector<int> ids(m);
    iota(ids.begin(), ids.end(), 0);
    for (int i = 0; i < m; i++)
        cin >> edges[i].first >> edges[i].second >> cost[i];
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return cost[i1] < cost[i2]; });
    for (int id : ids)
        if (!merge(edges[id].first, edges[id].second))
            res += max(0ll, cost[id]);
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