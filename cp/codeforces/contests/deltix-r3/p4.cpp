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

int dfs(vector<vector<int>> &g, vector<bool> &vis, int cur)
{
    vis[cur] = true;
    int cnt = 1;
    for (int e : g[cur])
        if (!vis[e])
            cnt += dfs(g, vis, e);
    return cnt;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(k), y(k);
    for (int i = 0; i < k; i++)
        cin >> x[i] >> y[i];
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < k; i++)
    {
        if (adj[x[i]][y[i]] == 0)
        {
            g[x[i]].pb(y[i]);
            g[y[i]].pb(x[i]);
            adj[x[i]][y[i]] = adj[y[i]][x[i]] = 1;
        }
        vector<bool> vis(n + 1);
        int rem = i + 1, mx = 0, c = 0;
        vector<int> seq;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j])
            {
                int cnt = dfs(g, vis, j);
                rem -= (cnt - 1);
                mx = max(mx, cnt - 1);
                seq.pb(cnt);
                c++;
            }
        }
        sort(seq.rbegin(), seq.rend());
        int res = mx;
        for (int j = 1; rem > 0 && j < (int)seq.size(); j++)
        {
            res += seq[j];
            rem--;
        }
        cout << res << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}