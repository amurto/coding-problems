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

const int N = 1005;
vector<int> g[N];
int sub[N];

int query(int Y)
{
    cout << "? " << Y << endl;
    int X;
    cin >> X;
    return X;
}

int dfs(vector<bool> &del, int cur, int last, int n)
{
    int centroid = 0;
    for (int e : g[cur])
        if (!del[e] && e != last)
            centroid = max(centroid, dfs(del, e, cur, n));
    bool pos = true;
    sub[cur] = 1;
    for (int e : g[cur])
    {
        if (!del[e] && e != last)
        {
            if (sub[e] > n / 2)
                pos = false;
            sub[cur] += sub[e];
        }
    }
    if (n - sub[cur] > n / 2)
        pos = false;
    if (pos)
        centroid = max(centroid, cur);
    return centroid;
}

int remove_dfs(vector<bool> &del, int cur, int last, int q)
{
    if (cur == q)
        return 0;
    int rem = 1;
    del[cur] = true;
    for (int e : g[cur])
        if (!del[e] && e != last)
            rem += remove_dfs(del, e, cur, q);
    return rem;
}

void solve()
{
    int n;
    cin >> n;
    int tot = n;
    vector<bool> del(n + 1);
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int ans = -1, cur = 1;
    for (int t = 1; ans == -1 && t <= 12; t++)
    {
        int centroid = dfs(del, cur, -1, n);
        dfs(del, centroid, -1, n);
        int q = query(centroid);
        if (q == -1)
            ans = centroid;
        else
        {
            n -= remove_dfs(del, centroid, -1, q);
            cur = q;
        }
    }
    cout << "! " << ans << endl;
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