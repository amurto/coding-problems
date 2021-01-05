#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 1;
int d[N], res[N];
bool vis[N];
void clrvis(int n)
{
    for (int i = 1; i <= n; i++)
        vis[i] = false;
}
void bfs(vector<vector<int>> &g, int n)
{
    int dis = 1;
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            int from = q.front();
            q.pop();
            for (int e : g[from])
            {
                if (vis[e])
                    continue;
                q.push(e);
                vis[e] = true;
                d[e] = dis;
            }
        }
        dis++;
    }
}

int dfs(vector<vector<int>> &g, int cur)
{
    if (vis[cur])
        return res[cur];
    vis[cur] = true;
    int dis = d[cur];
    for (int e : g[cur])
        if (d[e] > d[cur])
            dis = min(dis, dfs(g, e));
        else
            dis = min(dis, d[e]);
    res[cur] = dis;
    return res[cur];
}
void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
    }
    clrvis(n);
    bfs(g, n);
    clrvis(n);
    for (int i = 2; i <= n; i++)
        dfs(g, i);
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
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