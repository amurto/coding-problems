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
    vector<int> leaves;
    tree(int sz)
    {
        n = sz;
        g.resize(n + 1);
        leaves.resize(n + 1);
    }

    int calc_leaves(int cur, int last, int lvl)
    {
        array<int, 2> dp{lvl, lvl};
        for (int e : g[cur])
        {
            if (e != last)
            {
                dp[1] = max(dp[1], calc_leaves(e, cur, lvl + 1));
                if (dp[0] < dp[1])
                    swap(dp[0], dp[1]);
            }
        }
        if (dp[1] - 1 >= 0)
            leaves[dp[1] - 1] = max(leaves[dp[1] - 1], dp[0] + dp[1] - 2 * lvl);
        return dp[0];
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
    int mx = tr.calc_leaves(1, 1, 0);
    for (int i = n - 1; i >= 0; i--)
        tr.leaves[i] = max(tr.leaves[i], tr.leaves[i + 1]);
    for (int i = 0; i < mx; i++)
        tr.leaves[i] = (tr.leaves[i] + 1) / 2;
    for (int i = 1; i <= n; i++)
        res[i] = mx;
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        while (j < mx && tr.leaves[j] + i > j)
            j++;
        res[i] = min(res[i], j);
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