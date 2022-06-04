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
    int n, m, q;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<vector<ll>> ans(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> q;
    vector<int> mx(n + 1), X(q), K(q);
    for (int i = 0; i < q; i++)
    {
        cin >> X[i] >> K[i];
        mx[X[i]] = max(mx[X[i]], K[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        queue<int> que;
        set<int> vis;
        ll cur = 0;
        for (int j = 0; j <= mx[i]; j++)
        {
            if (j == 0)
            {
                cur += i;
                vis.insert(i);
                que.push(i);
            }
            else
            {
                int sz = (int)que.size();
                while (sz > 0)
                {
                    int v = que.front();
                    que.pop();
                    for (int e : g[v])
                    {
                        if (!vis.count(e))
                        {
                            cur += e;
                            vis.insert(e);
                            que.push(e);
                        }
                    }
                    sz--;
                }
            }
            ans[i].pb(cur);
        }
    }
    for (int i = 0; i < q; i++)
        cout << ans[X[i]][K[i]] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}