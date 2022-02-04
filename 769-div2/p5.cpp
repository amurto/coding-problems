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

struct tree
{
    int n;
    vector<vector<int>> g;
    vector<int> tin, tout, dep, mx_dep, vis;
    tree(int sz)
    {
        n = sz;
        g.resize(n + 1);
        tin.resize(n + 1);
        tout.resize(n + 1);
        dep.resize(n + 1);
        mx_dep.resize(n + 1);
    }

    int precompute(int cur, int last, int t, int lvl)
    {
        tin[cur] = tout[cur] = t;
        dep[cur] = lvl;
        for (int e : g[cur])
        {
            if (e != last)
            {
                tout[cur] = precompute(e, cur, tout[cur] + 1, lvl + 1);
                mx_dep[cur] = max(mx_dep[cur], mx_dep[e] + 1);
            }
        }
        return tout[cur];
    }

    int dfs(int cur, int last, int pmx, int x)
    {
        int ans = pmx;
        if (dep[cur] + mx_dep[cur] > x)
            ans = max(ans, mx_dep[cur]);
        array<int, 2> cnt{0, 0};
        for (int e : g[cur])
        {
            if (e != last)
            {
                if (dep[e] + mx_dep[e] > x)
                    cnt[1] = max(cnt[1], mx_dep[e] + 1);
                if (cnt[1] > cnt[0])
                    swap(cnt[0], cnt[1]);
            }
        }
        for (int e : g[cur])
        {
            if (e != last)
            {
                int far = 0;
                if (dep[cur] > x)
                    far = 1;
                if (pmx > 0)
                    far = max(far, pmx + 1);
                int cur_dep = 0;
                if (dep[e] + mx_dep[e] > x)
                    cur_dep = mx_dep[e] + 1;
                if (cnt[0] == cur_dep)
                {
                    if (cnt[1] > 0)
                        far = max(far, cnt[1] + 1);
                }
                else
                {
                    if (cnt[0] > 0)
                        far = max(far, cnt[0] + 1);
                }
                ans = min(ans, dfs(e, cur, far, x));
            }
        }
        return ans;
    }

    int calc(int x)
    {
        return dfs(1, 1, 0, x);
    }
};

void solve()
{
    int n;
    cin >> n;
    tree tr(n);
    vector<int> res(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tr.g[u].pb(v);
        tr.g[v].pb(u);
    }
    tr.precompute(1, 1, 0, 0);
    int mx = tr.mx_dep[1];
    for (int i = 1; i <= n; i++)
        res[i] = mx;
    vector<int> deps(mx);
    for (int i = 0; i < mx; i++)
        deps[i] = tr.calc(i);
    for (int i = 1; i <= n; i++)
    {
        int ans = n + 1;
        for (int j = 0; j < mx; j++)
            ans = min(ans, max(j, deps[j] + i));
        res[i] = min(res[i], ans);
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}