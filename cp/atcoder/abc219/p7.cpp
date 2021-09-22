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

const int N = 2e5 + 5, B = 500;
vector<int> g[N], gt[N];

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> deg(n + 1), heavy(n + 1), prev(n + 1), queries(q + 1), col(n + 1), last(n + 1), q_col(q + 1);
    iota(col.begin(), col.end(), 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1; i <= n; i++)
        if (deg[i] > B)
            heavy[i] = 1;
    for (int i = 1; i <= n; i++)
        for (int e : g[i])
            if (heavy[e])
                gt[i].pb(e);
    for (int i = 1; i <= q; i++)
    {
        cin >> queries[i];
        for (int e : gt[queries[i]])
        {
            if (last[e] > prev[queries[i]])
            {
                col[queries[i]] = q_col[last[e]];
                prev[queries[i]] = last[e];
            }
        }
        q_col[i] = col[queries[i]];
        if (heavy[queries[i]])
            last[queries[i]] = i;
        else
        {
            for (int e : g[queries[i]])
            {
                prev[e] = i;
                col[e] = col[queries[i]];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int e : gt[i])
        {
            if (last[e] > prev[i])
            {
                col[i] = q_col[last[e]];
                prev[i] = last[e];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << col[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}