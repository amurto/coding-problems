#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, q, t, u, v, cur = 0;
    cin >> n >> m;
    vector<set<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    for (int i = 1; i <= n; i++)
        if (g[i].empty() || *g[i].rbegin() < i)
            cur++;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t < 3)
        {
            cin >> u >> v;
            if (t == 1)
            {
                if (g[u].empty() || *g[u].rbegin() < u)
                    cur--;
                if (g[v].empty() || *g[v].rbegin() < v)
                    cur--;
                g[u].insert(v);
                g[v].insert(u);
                if (*g[u].rbegin() < u)
                    cur++;
                if (*g[v].rbegin() < v)
                    cur++;
            }
            else
            {
                if (g[u].empty() || *g[u].rbegin() < u)
                    cur--;
                if (g[v].empty() || *g[v].rbegin() < v)
                    cur--;
                g[u].erase(v);
                g[v].erase(u);
                if (g[u].empty() || *g[u].rbegin() < u)
                    cur++;
                if (g[v].empty() || *g[v].rbegin() < v)
                    cur++;
            }
        }
        else
            cout << cur << "\n";
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