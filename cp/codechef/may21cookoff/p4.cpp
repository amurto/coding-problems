#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, q, t, x, y, m = 0;
    cin >> n;
    vector<int> arr(n), p(n), con(n), pos(n), szc(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    vector<bool> vis(n);
    int comp = 0;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            g[comp].pb(i);
            con[i] = comp;
            int cur = p[i];
            while (!vis[cur])
            {
                vis[cur] = true;
                con[cur] = comp;
                g[comp].pb(cur);
                cur = p[cur];
            }
            int sz = g[comp].size();
            szc[comp] = sz;
            for (int j = 0; j < sz; j++)
                g[comp].pb(g[comp][j]);
            for (int j = 0; j < sz; j++)
                g[comp].pb(g[comp][j]);
            for (int j = 0; j < g[comp].size(); j++)
                pos[g[comp][j]] = j;
            comp++;
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t == 1)
            m++;
        else if (t == 2)
        {
            cin >> x >> y;
            x--;
            y--;
            swap(con[x], con[y]);
            swap(pos[x], pos[y]);
        }
        else
        {
            cin >> x;
            x--;
            int last = m;
            last %= szc[con[x]];
            cout << arr[g[con[x]][pos[x] - last]] << "\n";
        }
    }
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