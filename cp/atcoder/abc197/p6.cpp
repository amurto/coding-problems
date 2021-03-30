#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int inf = 1e9 + 5;
int solve()
{
    int n, m, u, v, t = 1, res = inf;
    char ch;
    cin >> n >> m;
    vector<vector<bool>> d(n + 1, vector<bool>(n + 1));
    vector<vector<vector<int>>> st(n + 1, vector<vector<int>>(26));
    vector<vector<vector<pii>>> adj(n + 1, vector<vector<pii>>(n + 1));
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> ch;
        d[u][v] = d[v][u] = true;
        st[u][ch - 'a'].pb(v);
        st[v][ch - 'a'].pb(u);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 0; k < 26; k++)
                for (int x : st[i][k])
                    for (int y : st[j][k])
                        adj[i][j].pb({x, y});
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, inf));
    dis[1][n] = 0;
    queue<pii> q;
    q.push({1, n});
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            pii p = q.front();
            q.pop();
            for (pii e : adj[p.first][p.second])
            {
                if (t < dis[e.first][e.second])
                {
                    dis[e.first][e.second] = t;
                    q.push(e);
                }
            }
        }
        t++;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (dis[i][j] < inf)
                if (i == j)
                    res = min(res, 2 * dis[i][j]);
                else if (d[i][j])
                    res = min(res, 2 * dis[i][j] + 1);
    return res >= inf ? -1 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}