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

const int N = 5e5 + 5;
vector<int> g[N];

int calc(int root, int n, int k)
{
    vector<int> vis1(n + 1), vis2(n + 1), dep(n + 1), idx(n + 1), dp(n + 1);
    vector<vector<int>> st(n + 1);
    auto precompute = [&](const auto &self, int cur, int last, int t, int lvl) -> int
    {
        vis1[cur] = vis2[cur] = t;
        idx[vis1[cur]] = cur;
        dep[cur] = lvl;
        st[dep[cur]].pb(vis1[cur]);
        for (int e : g[cur])
            if (e != last)
                vis2[cur] = self(self, e, cur, vis2[cur] + 1, lvl + 1);
        return vis2[cur];
    };
    precompute(precompute, root, root, 0, 0);
    auto dfs = [&](const auto &self, int cur, int last) -> void
    {
        dp[cur] = 1;
        int req_dep = dep[cur] + k;
        for (int e : g[cur])
        {
            if (e != last)
            {
                self(self, e, cur);
                if (req_dep <= n)
                {
                    int l = lower_bound(st[req_dep].begin(), st[req_dep].end(), vis1[e]) - st[req_dep].begin();
                    if (l < (int)st[req_dep].size())
                    {
                        int mx = 0;
                        int r = upper_bound(st[req_dep].begin(), st[req_dep].end(), vis1[e]) - st[req_dep].begin();
                        for (int j = l; j < r; j++)
                            mx = max(mx, dp[idx[st[req_dep][j]]]);
                        dp[cur] += mx;
                    }
                }
            }
        }
    };
    dfs(dfs, root, root);
    return dp[root];
}

int solve()
{
    int n, k, res = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        res = max(res, calc(i, n, k));
    return res;
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