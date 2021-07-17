// https://codeforces.com/contest/1029/problem/E
// Tree with Small Distances

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
vector<int> g[N];
int dp[N][4], pdp[N][4];
// 0 -> parent is unreachable
// 1 -> grandparent has edge
// 2 -> parent has edge
// 3 -> parent is 1

void dfs(int cur, int last)
{
    if (g[cur].size() == 1)
    {
        dp[cur][3] = dp[cur][2] = 0;
        dp[cur][1] = dp[cur][0] = 1;
        return;
    }
    for (int e : g[cur])
        if (e != last)
            dfs(e, cur);
    pdp[cur][0] = pdp[cur][1] = pdp[cur][2] = pdp[cur][3] = 0;
    for (int e : g[cur])
        if (e != cur)
            for (int k = 0; k < 4; k++)
                pdp[cur][k] += dp[e][k];
    for (int k = 0; k < 4; k++)
    {
        int res = 1 + pdp[cur][2];
        if (k == 1)
        {
            for (int e : g[cur])
                if (e != last)
                    res = min(res, pdp[cur][1] - dp[e][1] + dp[e][0]);
        }
        else if (k > 1)
            res = min(res, pdp[cur][k - 1]);
        dp[cur][k] = res;
    }
}

int solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int res = 0;
    for (int e : g[1])
        dfs(e, 1);
    for (int e : g[1])
        res += dp[e][3];
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