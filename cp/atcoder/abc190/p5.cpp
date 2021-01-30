#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 1, K = 20;
const ll inf = 1e8;
vector<vector<ll>> adj(K, vector<ll>(K, inf));
vector<int> g[N];
unordered_map<int, int> c, rc;

ll dp[K][1 << K];

void bfs(int node, int id, int n)
{
    vector<bool> vis(n + 1);
    queue<int> q;
    q.push(node);
    vis[node] = true;
    adj[id][id] = 0;
    ll d = 1;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            int cur = q.front();
            q.pop();
            for (int e : g[cur])
            {
                if (vis[e])
                    continue;
                vis[e] = true;
                q.push(e);
                adj[id][c[e]] = d;
            }
        }
        d++;
    }
    return;
}

ll mo(int last, int mask, int k, int fin)
{
    if (mask == fin)
        return 0;
    if (dp[last][mask] == -1)
    {
        ll res = inf;
        for (int i = 0; i < k; i++)
        {
            if (mask & (1 << i))
                continue;
            res = min(res, adj[last + 1][i + 1] + mo(i, mask | (1 << i), k, fin));
        }
        dp[last][mask] = res;
    }
    return dp[last][mask];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v, k;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> v;
        c[v] = i;
        rc[i] = v;
    }
    for (int i = 1; i <= k; i++)
        bfs(rc[i], i, n);
    memset(dp, -1, sizeof(dp));
    int fin = 0;
    for (int i = 0; i < k; i++)
        fin |= (1 << i);
    ll res = inf;
    for (int i = 0; i < k; i++)
        res = min(res, 1 + mo(i, 1 << i, k, fin));
    res >= inf ? cout << "-1\n" : cout << res << "\n";
    return 0;
}