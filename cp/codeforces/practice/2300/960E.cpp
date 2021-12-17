// https://codeforces.com/contest/960/problem/E
// Alternating Tree

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

const int MOD = 1e9 + 7, N = 2e5 + 5;
vector<int> g[N];
int col[N], V[N], contrib[N], sub[N][2];
// sub[i][0] -> '0' nodes in subtree
// sub[i][1] -> '1' nodes in subtree

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

void set_sz(int cur, int par, int dep)
{
    contrib[cur] = 0;
    col[cur] = dep;
    sub[cur][0] = sub[cur][1] = 0;
    sub[cur][col[cur]]++;
    for (int e : g[cur])
    {
        if (e != par)
        {
            set_sz(e, cur, dep ^ 1);
            for (int t = 0; t < 2; t++)
                sub[cur][t] += sub[e][t];
        }
    }
}

int dfs(int cur, int par, int a, int b, int n)
{
    int res = 0, sub_nodes = sub[cur][0] + sub[cur][1];
    if (col[cur] == 0)
        contrib[cur] = mul(sub_nodes, add(a, -b));
    else
        contrib[cur] = mul(sub_nodes, add(b, -a));
    a += sub[cur][0];
    b += sub[cur][1];
    contrib[cur] = add(contrib[cur], n);
    for (int e : g[cur])
    {
        if (e != par)
        {
            int ta = sub[e][0], tb = sub[e][1];
            if (col[cur] == 0)
            {
                contrib[cur] = add(contrib[cur], mul(ta, n - ta - tb));
                contrib[cur] = add(contrib[cur], -mul(tb, n - ta - tb));
            }
            else
            {
                contrib[cur] = add(contrib[cur], -mul(ta, n - ta - tb));
                contrib[cur] = add(contrib[cur], mul(tb, n - ta - tb));
            }
            res = add(res, dfs(e, cur, a - ta, b - tb, n));
        }
    }
    res = add(res, mul(contrib[cur], V[cur]));
    return res;
}

int solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> V[i];
        V[i] = add(V[i], 0);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    set_sz(1, 0, 0);
    return dfs(1, 0, 0, 0, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}