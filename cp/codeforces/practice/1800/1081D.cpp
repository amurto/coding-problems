// https://codeforces.com/contest/1081/problem/D
// Maximum Distance

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
#define pb push_back

const int N = 1e5 + 5;
int parent[N], cap[N], mx[N];
bool x[N];
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        mx[i] = 0;
        parent[i] = i;
        cap[i] = (x[i]) ? 1 : 0;
    }
}

int root(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = root(parent[x]);
}

void merge(int x, int y, int w, int k, bool &f, int &res)
{
    int rx = root(x), ry = root(y);
    if (rx == ry)
        return;
    // by size (capacity)
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
    mx[rx] = max({mx[rx], mx[ry], w});
    if (f && cap[rx] == k)
    {
        res = mx[rx];
        f = false;
    }
}

void solve()
{
    int n, m, k, u, v, w, res = 0;
    bool f = true;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        x[i] = false;
    for (int i = 0; i < k; i++)
    {
        cin >> u;
        x[u] = true;
    }
    init(n);
    vector<piii> edge;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edge.pb({w, {u, v}});
    }
    sort(edge.begin(), edge.end());
    for (int i = 0; f && i < m; i++)
        merge(edge[i].second.first, edge[i].second.second, edge[i].first, k, f, res);
    for (int i = 1; i <= k; i++)
        cout << res << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}