// https://codeforces.com/contest/369/problem/C
// Valera and Elections

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 1;
vector<pair<int, int>> g[N];
bool vis[N], p[N], fix[N];

void init(int n)
{
    for (int i = 1; i <= n; i++)
        vis[i] = p[i] = fix[i] = false;
}
void dfs(int cur, int bad)
{
    p[bad] = true;
    vis[cur] = true;
    for (pair<int, int> e : g[cur])
    {
        if (!vis[e.first])
        {
            if (e.second == 2)
            {
                fix[bad] = true;
                dfs(e.first, e.first);
            }
            else
                dfs(e.first, bad);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, u, v, t;
    cin >> n;
    init(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> t;
        g[u].pb({v, t});
        g[v].pb({u, t});
    }
    dfs(1, 0);
    vector<int> res;
    for (int i = 1; i <= n; i++)
        if (p[i] && !fix[i])
            res.pb(i);
    cout << res.size() << "\n";
    for (int r : res)
        cout << r << " ";
    return 0;
}