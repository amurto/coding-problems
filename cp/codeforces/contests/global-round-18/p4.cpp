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
typedef pair<pair<int, int>, int> piii;
#define pb push_back

const int N = 2e5 + 5;
vector<pii> tree[N], g[N];
int px[N], rx[N];

int calc(int v)
{
    return __builtin_popcount(v) & 1;
}

void set_rx(int cur, int last)
{
    for (pii e : tree[cur])
    {
        if (e.first != last && e.second != -1)
        {
            rx[e.first] = rx[cur] ^ calc(e.second);
            set_rx(e.first, cur);
        }
    }
}

bool calc_rx(vector<piii> &edges, int cur, int last)
{
    for (pii e : tree[cur])
    {
        if (e.first != last)
        {
            int val = rx[cur] ^ rx[e.first];
            if (e.second >= 0 && val != calc(e.second))
                return false;
            if (e.second >= 0)
                val = e.second;
            px[e.first] = px[cur] ^ calc(val);
            edges.pb({{cur, e.first}, val});
            if (!calc_rx(edges, e.first, cur))
                return false;
        }
    }
    return true;
}

bool dfs(vector<bool> &vis, int cur)
{
    vis[cur] = true;
    for (pii e : g[cur])
    {
        if (!vis[e.first])
        {
            // rx[cur]^rx[e.first] = e.second
            int tmp = rx[cur] ^ e.second;
            if (rx[e.first] != -1 && rx[e.first] != tmp)
                return false;
            rx[e.first] = tmp;
            if (!dfs(vis, e.first))
                return false;
        }
    }
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        tree[i].clear();
        g[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        tree[x].pb({y, v});
        tree[y].pb({x, v});
        if (v >= 0)
        {
            g[x].pb({y, calc(v)});
            g[y].pb({x, calc(v)});
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, p;
        cin >> a >> b >> p;
        g[a].pb({b, p});
        g[b].pb({a, p});
    }
    for (int i = 2; i <= n; i++)
        rx[i] = -1;
    px[1] = rx[1] = 0;
    set_rx(1, 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && rx[i] >= 0)
        {
            if (!dfs(vis, i))
            {
                cout << "NO\n";
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            rx[i] = 0;
            if (!dfs(vis, i))
            {
                cout << "NO\n";
                return;
            }
        }
    }
    vector<piii> edges;
    if (!calc_rx(edges, 1, 1))
    {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        for (pii e : g[i])
            if ((px[i] ^ px[e.first]) != e.second)
            {
                cout << "NO\n";
                return;
            }
    cout << "YES\n";
    for (piii e : edges)
        cout << e.first.first << " " << e.first.second << " " << e.second << "\n";
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