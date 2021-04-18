// https://codeforces.com/contest/1242/problem/B
// 0-1 MST

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
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
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
}

int solve()
{
    int n, m, u, v, comp = 0;
    cin >> n >> m;
    init(n);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    vector<int> nodes(n);
    iota(nodes.begin(), nodes.end(), 1);
    sort(nodes.begin(), nodes.end(), [&](int &i1, int &i2) {
        return g[i1].size() < g[i2].size();
    });
    for (int i : nodes)
    {
        set<int> mst;
        for (int e : g[i])
        {
            st.erase(e);
            mst.insert(e);
        }
        for (int x : st)
            merge(i, x);
        st = mst;
        st.insert(root(i));
    }
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int rt = root(i);
        if (!vis[rt])
        {
            comp++;
            vis[rt] = true;
        }
    }
    return comp - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}