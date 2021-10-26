#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 3e5 + 5;
vector<int> g[N], tree[N];

void create_tree(vector<bool> &vis, int cur)
{
    vis[cur] = true;
    for (int e : g[cur])
    {
        if (!vis[e])
        {
            tree[cur].pb(e);
            tree[e].pb(cur);
            create_tree(vis, e);
        }
    }
}

bool find_path(vector<int> &path, int cur, int last, int b)
{
    bool v = (cur == b);
    for (int e : tree[cur])
        if (e != last && find_path(path, e, cur, b))
            v = true;
    if (v)
        path.pb(cur);
    return v;
}

void solve()
{
    int n, m, q;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> q;
    vector<int> a(q), b(q), cnt(n + 1);
    for (int i = 0; i < q; i++)
    {
        cin >> a[i] >> b[i];
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    array<int, 2> p{0, 0};
    for (int i = 1; i <= n; i++)
        p[cnt[i] & 1]++;
    if (p[1] > 0)
    {
        cout << "NO\n";
        cout << p[1] / 2 << "\n";
        return;
    }

    vector<bool> vis(n + 1);
    create_tree(vis, 1);
    cout << "YES\n";
    for (int i = 0; i < q; i++)
    {
        vector<int> path;
        find_path(path, a[i], -1, b[i]);
        reverse(path.begin(), path.end());
        cout << (int)path.size() << "\n";
        for (int x : path)
            cout << x << " ";
        cout << "\n";
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