#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> C(n + 1, -1), q, res;
    q.pb(1);
    C[1] = 1;
    for (int i = 0; i < q.size(); i++)
    {
        int u = q[i];
        if (C[u] == 1)
            res.pb(u);
        for (int v : g[u])
        {
            if (C[v] == -1)
            {
                C[v] = 1;
                q.pb(v);
            }
            C[v] &= !C[u];
        }
    }
    if (q.size() < n)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n"
         << res.size() << "\n";
    for (int r : res)
        cout << r << " ";
    cout << "\n";
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