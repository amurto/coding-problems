#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, u, v, c = 0;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> col(n + 1), sz(4);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; c < 3 && i <= n; i++)
    {
        if (col[i] > 0)
            continue;
        col[i] = ++c;
        vector<bool> adj(n + 1);
        for (int e : g[i])
            adj[e] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!adj[j])
            {
                if (col[j] > 0 && col[j] != col[i])
                {
                    cout << "-1\n";
                    return;
                }
                else
                    col[j] = col[i];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 0)
        {
            cout << "-1\n";
            return;
        }
        sz[col[i]]++;
    }
    int sum = sz[1] + sz[2] + sz[3];
    for (int i = 1; i <= 3; i++)
    {
        if (sz[i] == 0)
        {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int e : g[i])
        {
            if (col[i] == col[e])
            {
                cout << "-1\n";
                return;
            }
        }
        int edge = g[i].size();
        if (sum - sz[col[i]] != edge)
        {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << col[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}