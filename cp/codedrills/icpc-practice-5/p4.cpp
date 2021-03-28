#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
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
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
    return true;
}

void dfs(vector<int> &arr, vector<bool> &vis, vector<int> &g, int cur, int t)
{
    if (vis[cur])
        return;
    vis[cur] = true;
    g[cur] = t;
    dfs(arr, vis, g, arr[cur], t);
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1), c(n + 1), g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    vector<bool> vis(n + 1);
    int t = 1;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        dfs(arr, vis, g, arr[i], t);
        t++;
    }
    auto cmp = [&](int &i1, int &i2) {
        return c[i1] < c[i2];
    };
    sort(arr.begin(), arr.end(), cmp);
    vector<piii> edge;
    for (int i = 1; i < n; i++)
        if (g[arr[i]] != g[arr[i + 1]])
            edge.pb({abs(c[arr[i]] - c[arr[i + 1]]), {g[arr[i]], g[arr[i + 1]]}});
    sort(edge.begin(), edge.end());
    init(t + 5);
    ll res = 0;
    for (piii e : edge)
        if (merge(e.second.first, e.second.second))
            res += e.first * 1ll;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}