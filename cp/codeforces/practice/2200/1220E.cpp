// https://codeforces.com/contest/1220/problem/E
// Tourism

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
vector<int> g[N];
int w[N], dis[N], col[N];

void dfs1(int cur, int last)
{
    for (int e : g[cur])
        if (e != last)
            if (dis[cur] + 1 == dis[e])
                dfs1(e, cur);
            else
                col[cur] = col[e] = 1;
    for (int e : g[cur])
        if (e != last)
            col[cur] = max(col[cur], col[e]);
}

ll dfs2(int cur, int last, ll sum)
{
    ll res = sum + w[cur];
    for (int e : g[cur])
        if (e != last && dis[cur] + 1 == dis[e])
            res = max(res, dfs2(e, cur, sum + w[cur]));
    return res;
}

ll solve()
{
    int n, m, s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = n + 1;
        col[i] = 0;
    }
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int sz = q.size();
        while (sz > 0)
        {
            int cur = q.front();
            q.pop();
            for (int e : g[cur])
            {
                if (dis[e] > dis[cur])
                {
                    dis[e] = dis[cur] + 1;
                    q.push(e);
                }
            }
            sz--;
        }
    }
    dfs1(s, s);
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (col[i])
        {
            res += w[i];
            w[i] = 0;
        }
    }
    res += dfs2(s, s, 0);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}