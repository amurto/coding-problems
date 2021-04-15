// https://codeforces.com/contest/1328/problem/E
// Tree Queries

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;

vector<int> vis1(N), vis2(N), dep(N), par(N);
int dfs(vector<vector<int>> &g, int cur, int last, int t, int lvl)
{
    par[cur] = last;
    vis1[cur] = vis2[cur] = t;
    dep[cur] = lvl;
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
    int n, m, k, u, v;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(g, 1, 1, 0, 0);
    while (m-- > 0)
    {
        cin >> k;
        vector<int> arr(k);
        for (int i = 0; i < k; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end(), [&](int &i1, int &i2) {
            return dep[i1] < dep[i2];
        });
        bool path = true;
        int l = vis1[1], r = vis2[1];
        for (int i = 0; path && i < k;)
        {
            int p = par[arr[i]], d = dep[arr[i]], id = i, tl = vis1[arr[i]], tr = vis2[arr[i]];
            while (id < k && d == dep[arr[id]])
                id++;
            for (int j = i; j < id; j++)
                if (par[arr[j]] != p)
                    path = false;
            if (vis1[p] < l || vis2[p] > r)
                path = false;
            i = id;
            l = vis1[p];
            r = vis2[p];
        }
        path ? cout << "YES\n" : cout << "NO\n";
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