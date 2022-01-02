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
int par[N], dis[N], leaf[N];

int dfs(int cur, int last)
{
    par[cur] = last;
    dis[cur] = 1;
    leaf[cur] = cur;
    for (int e : g[cur])
    {
        if (e != last)
        {
            if (dfs(e, cur) + 1 > dis[cur])
            {
                dis[cur] = dis[e] + 1;
                leaf[cur] = leaf[e];
            }
        }
    }
    return dis[cur];
}

ll calc(int white, int diff)
{

    if (diff < 0 && abs(diff) > white)
    {
        int req = (abs(diff) - white) / 2;
        white += req;
        diff += req;
    }
    return white * 1ll * diff;
}

ll solve()
{
    int n, k;
    cin >> n >> k;
    ll res = -1e18;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    vector<bool> vis(n + 1);
    vis[0] = true;
    auto cmp = [&](int &i1, int &i2)
    {
        return dis[i1] < dis[i2];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    pq.push(1);
    int cnt = 0, nodes = 0;
    while (cnt < k && !pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        nodes += dis[cur];
        cnt++;
        int x = leaf[cur];
        while (!vis[x])
        {
            vis[x] = true;
            for (int e : g[x])
                if (e != par[x] && !vis[e])
                    pq.push(e);
            x = par[x];
        }
        int red = cnt, blue = n - nodes, white = nodes - cnt;
        int diff = red - blue;
        int inc = min(white, k - red);
        res = max(res, calc(white, diff));
        res = max(res, calc(white - inc, diff + inc));
        if (diff < white)
        {
            int req = (white - diff) / 2;
            if (req <= inc)
            {
                diff += req;
                white -= req;
                res = max(res, calc(white, diff));
            }
        }
    }
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