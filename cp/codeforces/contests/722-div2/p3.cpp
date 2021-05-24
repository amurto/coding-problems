#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
vector<int> g[N];
ll arr[N][2];
int p[N];

void precompute(int cur, int last)
{
    p[cur] = last;
    for (int e : g[cur])
        if (e != last)
            precompute(e, cur);
}

ll dfs(vector<vector<ll>> &dp, int cur, int d)
{
    if (dp[cur][d] == -1)
    {
        ll res = 0;
        for (int i = 0; i < 2; i++)
        {
            ll diff = 0;
            if (p[cur] != cur)
                diff = abs(arr[p[cur]][d] - arr[cur][i]);
            for (int e : g[cur])
                if (e != p[cur])
                    diff += dfs(dp, e, i);
            res = max(res, diff);
        }
        dp[cur][d] = res;
    }
    return dp[cur][d];
}

ll solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= n; i++)
        cin >> arr[i][0] >> arr[i][1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    precompute(1, 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));
    return dfs(dp, 1, 1);
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