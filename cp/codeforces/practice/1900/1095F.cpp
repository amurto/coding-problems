// https://codeforces.com/contest/1095/problem/F
// Make It Connected

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, pair<int, int>> piii;
#define pb push_back

const int N = 2e5 + 5;
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
    int n, m, k, u, v;
    ll w, mn = 0, res = 0;
    cin >> n >> m;
    init(n);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < arr[mn])
            mn = i;
    }
    vector<piii> edge;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edge.pb({w, {u, v}});
    }
    for (int i = 0; i < n; i++)
        if (i != mn)
            edge.pb({arr[mn] + arr[i], {mn + 1, i + 1}});
    sort(edge.begin(), edge.end());
    for (piii e : edge)
        if (merge(e.second.first, e.second.second))
            res += e.first;
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