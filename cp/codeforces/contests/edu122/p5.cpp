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

class edge
{
public:
    int id, u, v, w;
    edge() {}
    edge(int id, int u, int v, int w) : id(id), u(u), v(v), w(w) {}
};

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

vector<int> calc(vector<edge> &edges, vector<int> &ids, int n, int x)
{
    sort(ids.begin(), ids.end(), [&](int i1, int i2)
         { return abs(edges[i1].w - x) < abs(edges[i2].w - x); });
    dsu ds(n);
    vector<int> mst;
    for (int id : ids)
        if (ds.merge_nodes(edges[id].u, edges[id].v))
            mst.pb(id);
    return mst;
}

ll solve()
{
    int n, m, p, k, a, b, c;
    ll res = 0;
    cin >> n >> m;
    vector<edge> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.pb(edge(i, u, v, w));
    }
    cin >> p >> k >> a >> b >> c;
    vector<int> ids(m), pts;
    iota(ids.begin(), ids.end(), 0);
    vector<vector<int>> mst_ids;
    vector<vector<ll>> sums;
    pts.pb(0);
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            pts.pb(min(edges[i].w, edges[j].w) + (max(edges[i].w, edges[j].w) - min(edges[i].w, edges[j].w)) / 2 + 1);
    sort(pts.begin(), pts.end());
    pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
    for (int cur : pts)
    {
        vector<int> mst = calc(edges, ids, n, cur);
        for (int i = 0; i < n - 1; i++)
            mst[i] = edges[mst[i]].w;
        sort(mst.begin(), mst.end());
        mst_ids.pb(mst);
        ll sum = 0;
        vector<ll> pre(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            sum += 1ll * mst[i];
            pre[i] = sum;
        }
        sums.pb(pre);
    }
    int q = 0;
    for (int i = 0; i < k; i++)
    {
        if (i < p)
            cin >> q;
        else
            q = (q * 1ll * a + b) % c;
        int pt = upper_bound(pts.begin(), pts.end(), q) - pts.begin();
        pt--;
        ll ans = 0;
        int itr = upper_bound(mst_ids[pt].begin(), mst_ids[pt].end(), q) - mst_ids[pt].begin();
        ans += 1ll * q * (itr - (n - 1 - itr));
        ll rem = 0;
        if (itr > 0)
            rem = sums[pt][itr - 1];
        ans -= rem;
        ans += (sums[pt].back() - rem);
        res ^= ans;
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