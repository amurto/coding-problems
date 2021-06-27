#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 5e4 + 5, K = 1e3 + 5, inf = 1e8;
vector<int> g[N];
int vis[N][K], dp[N][K], mov[K], vis1[N], vis2[N], dep[N];

int dfs(int cur, int last, int t, int lvl)
{
    vis1[cur] = vis2[cur] = t;
    dep[cur] = lvl;
    int mx = vis1[cur];
    for (int e : g[cur])
        if (e != last)
            vis2[cur] = dfs(e, cur, vis2[cur] + 1, lvl + 1);
    return vis2[cur];
}

int calc(vector<int> &nodes, int cur, int sum, int n, int tc)
{
    if (sum == 0)
        return 0;
    if (cur >= n)
        return inf;
    if (vis[cur][sum] != tc)
    {
        vis[cur][sum] = tc;
        int node = nodes[cur], res = inf;
        int sub = vis2[node] - vis1[node] + 1;
        if (sum - sub >= 0)
            res = min(res, 1 + calc(nodes, cur + sub, sum - sub, n, tc));
        res = min(res, calc(nodes, cur + 1, sum, n, tc));
        dp[cur][sum] = res;
    }
    return dp[cur][sum];
}

int solve(int tc)
{
    int n, k, p;
    cin >> n >> k;
    vector<int> sdp(k + 1, inf);
    for (int i = 1; i <= n; i++)
    {
        vis1[i] = vis2[i] = 0;
        g[i].clear();
    }
    for (int i = 2; i <= n; i++)
    {
        cin >> p;
        g[p].pb(i);
        g[i].pb(p);
    }
    dfs(1, 1, 0, 0);
    vector<int> nodes;
    for (int i = 1; i <= n; i++)
        nodes.pb(i);
    sort(nodes.begin(), nodes.end(), [&](int &i1, int &i2)
         { return vis1[i1] < vis1[i2]; });
    mov[0] = 0;
    for (int i = 1; i <= k; i++)
        mov[i] = inf;
    for (int i = 1; i <= min(n, k); i++)
        mov[i] = calc(nodes, 0, i, n, tc);
    sdp[0] = 0;
    for (int j = 1; j <= k; j++)
        for (int i = 1; i <= j; i++)
            if (sdp[j - i] < inf & mov[i] < inf)
                sdp[j] = min(sdp[j], sdp[j - i] + mov[i] + 1);
    return sdp[k] - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(vis, 0, sizeof(vis));
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << solve(tc) << "\n";
    return 0;
}