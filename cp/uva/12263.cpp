// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3415
// 12263 - Rankings

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 501;
int g[N][N], deg[N];
bool vis[N];

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        deg[i] = 0;
        for (int j = 1; j <= n; j++)
            g[i][j] = 0;
        vis[i] = false;
    }
}

void topsort(int n)
{
    vector<int> res;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res.pb(u);
        for (int v = 1; v <= n; v++)
        {
            if (!g[u][v])
                continue;
            deg[v]--;
            if (deg[v] == 0)
                q.push(v);
        }
    }
    if (res.size() != n)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i];
        i == n - 1 ? cout << "\n" : cout << " ";
    }
}

void solve()
{
    int n, m, x, y, v;
    cin >> n;
    init(n);
    vector<int> rank(n + 1), res;
    for (int i = 0; i < n; i++)
        cin >> rank[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            g[rank[i]][rank[j]] = 1;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        swap(g[x][y], g[y][x]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            deg[i] += g[j][i];
    topsort(n);
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