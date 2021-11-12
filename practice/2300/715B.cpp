// https://codeforces.com/contest/715/problem/B
// Complete The Graph

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

const int N = 1e3 + 5, M = 1e4 + 5;
const ll inf = 1e10 + 5;
// {node, edge_id}
vector<pii> g[N][2];
int tp[M], u[M], v[M];
ll w[M];

void display(int m)
{
    cout << "YES\n";
    for (int i = 0; i < m; i++)
        cout << u[i] << " " << v[i] << " " << w[i] << "\n";
}

void solve()
{
    int n, m, s, t;
    ll L;
    cin >> n >> m >> L >> s >> t;
    for (int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        g[u[i]][w[i] > 0].pb({v[i], i});
        g[v[i]][w[i] > 0].pb({u[i], i});
        tp[i] = (w[i] > 0);
        if (w[i] == 0)
            w[i] = 1;
    }
    int k = min(n, m);
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, inf));
    vector<vector<int>> last_ver(n, vector<int>(k + 1, -1)), last_edge(n, vector<int>(k + 1, -1));
    dp[s][0] = 0;
    for (int j = 0; j <= k; j++)
    {
        if (j > 0)
        {
            for (int i = 0; i < n; i++)
            {
                for (pii e : g[i][0])
                {
                    if (dp[e.first][j - 1] + 1 < dp[i][j])
                    {
                        dp[i][j] = dp[e.first][j - 1] + 1;
                        last_ver[i][j] = e.first;
                        last_edge[i][j] = e.second;
                    }
                }
            }
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
            if (dp[i][j] < inf)
                pq.push({dp[i][j], i});

        while (!pq.empty())
        {
            pii cur = pq.top();
            pq.pop();
            if (!vis[cur.second])
            {
                vis[cur.second] = true;
                for (pii e : g[cur.second][1])
                {
                    if (!vis[e.first] && dp[cur.second][j] + w[e.second] < dp[e.first][j])
                    {
                        dp[e.first][j] = dp[cur.second][j] + w[e.second];
                        last_ver[e.first][j] = cur.second;
                        last_edge[e.first][j] = e.second;
                        pq.push({dp[e.first][j], e.first});
                    }
                }
            }
        }
        if (j == 0)
        {
            if (dp[t][0] < L)
            {
                cout << "NO\n";
                return;
            }
            else if (dp[t][0] == L)
            {
                for (int i = 0; i < m; i++)
                    if (tp[i] == 0)
                        w[i] = L + 1;
                display(m);
                return;
            }
        }
        else if (dp[t][j] <= L)
        {
            ll req = L - dp[t][j];
            int cur = t, e = j;
            while (cur != s)
            {
                int tmp = e;
                if (tp[last_edge[cur][e]] == 0)
                {
                    w[last_edge[cur][e]] += req;
                    req = 0;
                    tp[last_edge[cur][e]] = -1;
                    tmp--;
                }
                cur = last_ver[cur][e];
                e = tmp;
            }
            for (int i = 0; i < m; i++)
                if (tp[i] == 0)
                    w[i] = L + 1;
            display(m);
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}