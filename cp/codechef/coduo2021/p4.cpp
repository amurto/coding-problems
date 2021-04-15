#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 2e5 + 5, M = 12, inf = 1e9;
vector<pii> g[N];
int B[N], cnt[5], dp[M][M][M][M][M], D[5][M];

// adjacency list
// g[u] = [[v,w]]
void dijkstra(int n, int source, int id, vector<int> &nwoff)
{

    vector<int> dis(n, inf);
    vector<bool> vis(n);
    dis[source] = 0;

    // min heap
    // {dis[v], v}
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dis[source], source});

    while (!pq.empty())
    {
        pii from = pq.top();
        pq.pop();
        if (vis[from.second])
            continue;
        vis[from.second] = true;
        for (pii to : g[from.second])
        {
            if (!vis[to.first])
            {
                if (dis[from.second] + to.second < dis[to.first])
                    dis[to.first] = dis[from.second] + to.second;
                pq.push({dis[to.first], to.first});
            }
        }
    }
    for (int i = 0; i < nwoff.size(); i++)
        D[id][i] = dis[nwoff[i]];
}

int sarkar(int cur, int k, int p, vector<int> st)
{
    if (cur == p)
        return 0;
    if (dp[cur][st[0]][st[1]][st[2]][st[3]] == -1)
    {
        int res = inf;
        for (int j = 0; j < k; j++)
        {
            if (st[j] + 1 >= cnt[j])
                continue;
            st[j]++;
            res = min(res, D[j][cur] + sarkar(cur + 1, k, p, st));
            st[j]--;
        }
        dp[cur][st[0]][st[1]][st[2]][st[3]] = res;
    }
    return dp[cur][st[0]][st[1]][st[2]][st[3]];
}

int solve()
{
    int n, m, k, p, u, v, z;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> z;
        g[u].pb({v, z});
        g[v].pb({u, z});
    }
    cin >> k;
    vector<int> office(k);
    for (int i = 0; i < k; i++)
        cin >> office[i] >> cnt[i];
    cin >> p;
    vector<int> nwoff(p);
    for (int i = 0; i < p; i++)
        cin >> nwoff[i];
    for (int i = 0; i < k; i++)
        dijkstra(n + 1, office[i], i, nwoff);
    memset(dp, -1, sizeof(dp));
    vector<int> st = {0, 0, 0, 0};
    int res = sarkar(0, k, p, st);
    return res >= inf ? -1 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}