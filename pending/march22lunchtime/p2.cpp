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

void solve()
{
    int n, m, queries;
    cin >> n >> m >> queries;
    vector<bool> vis(n + 1);
    vector<vector<int>> g(n + 1);
    queue<int> q;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 0; i < queries; i++)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1)
        {
            if (!vis[x])
            {
                vis[x] = true;
                q.push(x);
            }
        }
        else if (t == 2)
        {
            while (!q.empty() && x > 0)
            {
                int sz = (int)q.size();
                while (sz > 0)
                {
                    int cur = q.front();
                    q.pop();
                    for (int e : g[cur])
                    {
                        if (!vis[e])
                        {
                            vis[e] = true;
                            q.push(e);
                        }
                    }
                    sz--;
                }
                x--;
            }
        }
        else
        {
            vis[x] ? cout << "YES\n" : cout << "NO\n";
        }
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
