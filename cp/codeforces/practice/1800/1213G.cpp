// https://codeforces.com/contest/1213/problem/G
// Path Queries

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
#define pb push_back

const int N = 2e5 + 5;
int parent[N], cap[N];

ll nc2(int n)
{
    return n * 1ll * (n - 1) / 2;
}

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

ll merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    ll sum = nc2(cap[rx] + cap[ry]) - nc2(cap[rx]) - nc2(cap[ry]);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
    return sum;
}

void solve()
{
    int n, m, u, v, w, q;
    cin >> n >> m;
    init(n);
    vector<vector<int>> g(n + 1);
    vector<piii> e;
    vector<ll> st(N);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        e.pb({w, {u, v}});
    }
    sort(e.begin(), e.end());
    int prev = 0;
    for (int i = 0; i < n - 1; i++)
    {
        st[e[i].first] = st[prev];
        st[e[i].first] += merge(e[i].second.first, e[i].second.second);
        prev = e[i].first;
    }
    for (int i = 1; i < N; i++)
        st[i] = max(st[i - 1], st[i]);
    while (m-- > 0)
    {
        cin >> q;
        cout << st[q] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}