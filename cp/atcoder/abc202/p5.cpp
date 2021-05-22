#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
// Entry and Exit time
vector<int> vis1(N), vis2(N), dep(N);
vector<vector<int>> step(N);
int dfs(vector<vector<int>> &g, int cur, int last, int t, int lvl)
{
    vis1[cur] = vis2[cur] = t;
    dep[cur] = lvl;
    step[dep[cur]].pb(vis1[cur]);
    if (g[cur].size() == 1 && g[cur][0] == last)
        return vis1[cur];
    int mx = vis1[cur];
    for (int e : g[cur])
        if (e != last)
            vis2[cur] = dfs(g, e, cur, vis2[cur] + 1, lvl + 1);
    return vis2[cur];
}

void solve()
{
    int n, p, q, u, d;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> p;
        g[p].pb(i);
        g[i].pb(p);
    }
    dfs(g, 1, 1, 0, 0);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> u >> d;
        int ub = upper_bound(step[d].begin(), step[d].end(), vis2[u]) - step[d].begin();
        int lb = lower_bound(step[d].begin(), step[d].end(), vis1[u]) - step[d].begin();
        cout << ub - lb << "\n";
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