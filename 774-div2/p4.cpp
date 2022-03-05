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
vector<int> g[N], st[2][N][2];
int deg[N], W[N], dp[N][2], sum[N][2];

// dp[cur][0] -> good
// dp[cur][1] -> bad
void dfs(int cur, int last)
{
    for (int e : g[cur])
        if (e != last)
            dfs(e, cur);

    // good, make W[cur] = deg[cur]
    // dp[cur][0]
    dp[cur][0] = 1;
    sum[cur][0] = deg[cur];
    for (int e : g[cur])
    {
        if (e != last)
        {
            int t = 0;
            if (deg[e] == 1 && deg[cur] == 1)
            {

                if (dp[e][0] > dp[e][1])
                    t = 0;
                else if (dp[e][0] == dp[e][1])
                {
                    if (sum[e][0] > sum[e][1])
                        t = 1;
                }
                else
                {
                    t = 1;
                }
            }
            else
            {
                t = 1;
            }
            sum[cur][0] += sum[e][t];
            dp[cur][0] += dp[e][t];
            st[0][cur][t].pb(e);
        }
    }

    // bad, make W[cur] = 1
    // dp[cur][1]
    dp[cur][1] = 0;
    sum[cur][1] = 0;
    for (int e : g[cur])
    {
        if (e != last)
        {
            int t = 0;

            if (dp[e][0] > dp[e][1])
                t = 0;
            else if (dp[e][0] == dp[e][1])
            {
                if (sum[e][0] > sum[e][1])
                    t = 1;
            }
            else
                t = 1;

            sum[cur][1] += sum[e][t];
            dp[cur][1] += dp[e][t];
            st[1][cur][t].pb(e);
        }
    }
}

void construct_ans(int cur, int t)
{
    if (t == 0)
        W[cur] = deg[cur];
    else
        W[cur] = 1;
    for (int c = 0; c < 2; c++)
        for (int e : st[t][cur][c])
            construct_ans(e, c);
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        deg[i] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    dfs(1, 1);

    int t = 0;
    if (dp[1][0] < dp[1][1])
        t = 1;
    else if (dp[1][0] == dp[1][1])
        if (sum[1][0] > sum[1][1])
            t = 1;
    construct_ans(1, t);

    int good = 0, tot = 0;
    for (int i = 1; i <= n; i++)
    {
        int s = 0;
        for (int e : g[i])
            s += W[e];
        if (W[i] == s)
            good++;
        tot += W[i];
    }

    cout << good << " " << tot << "\n";
    for (int i = 1; i <= n; i++)
        cout << W[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}