// https://codeforces.com/contest/788/problem/B
// Weird journey

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

const int N = 1e6 + 5;
int parent[N], cap[N], edge_cnt[N];

ll nc2(int n)
{
    return (n * 1ll * (n - 1)) / 2;
}

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        cap[i] = 1;
        edge_cnt[i] = 0;
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
    edge_cnt[rx] += edge_cnt[ry];
    parent[ry] = parent[rx];
}

ll solve()
{
    int n, m, u, v, loops = 0;
    cin >> n >> m;
    ll res = 0;
    vector<int> deg(n + 1);
    init(n);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        if (u == v)
            loops++;
        else
        {
            deg[u]++;
            deg[v]++;
            merge(u, v);
        }
        edge_cnt[root(u)]++;
    }
    if (edge_cnt[root(v)] != m)
        return 0;
    for (int i = 1; i <= n; i++)
        res += nc2(deg[i]);
    res += loops * 1ll * (m - loops) + nc2(loops);
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