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

const int N = 1e5 + 5;
int parent[N], cap[N];
vector<int> g[N];

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

void dfs(vector<int> &st, vector<bool> &vis, int cur)
{
    vis[cur] = true;
    st.pb(cur);
    for (int e : g[cur])
        if (!vis[e])
            dfs(st, vis, e);
}

void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    ll res = 0;
    vector<ll> arr(n + 1);
    vector<pii> edges;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        g[i].clear();
    init(n);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
    }
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vector<int> st;
            dfs(st, vis, i);
            for (int x : st)
                for (int e : g[x])
                    if (merge(x, e))
                        edges.pb({x, e});
        }
    }
    vector<int> seq(n);
    iota(seq.begin(), seq.end(), 1);
    sort(seq.begin(), seq.end(), [&](int &i1, int &i2)
         { return arr[i1] < arr[i2]; });
    vector<pii> mst;
    for (int i = 1; i < seq.size(); i++)
        if (root(seq[i - 1]) != root(seq[i]))
            mst.pb({seq[i - 1], seq[i]});
    sort(mst.begin(), mst.end(), [&](pii &p1, pii &p2)
         { return abs(arr[p1.first] - arr[p1.second]) < abs(arr[p2.first] - arr[p2.second]); });
    for (pii e : mst)
    {
        if (merge(e.first, e.second))
        {
            res += abs(arr[e.first] - arr[e.second]);
            edges.pb(e);
        }
    }
    int k = (int)edges.size();
    cout << res << " " << k << "\n";
    for (pii e : edges)
        cout << e.first << " " << e.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}