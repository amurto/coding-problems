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
int par[N], dp[N], leaves[N];
int dfs(int cur, int last)
{
    dp[cur] = leaves[cur] = 0;
    for (int e : g[cur])
    {
        if (e != last)
        {
            leaves[cur] += dfs(e, cur);
            dp[cur] += dp[e];
        }
    }
    if (cur != 1)
        dp[cur] += max(0, leaves[cur] - 1);
    return leaves[cur] > 0 ? 0 : 1;
}

int solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 1);
    int res = leaves[1] + dp[1];
    if (leaves[1] == 0)
        res++;
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