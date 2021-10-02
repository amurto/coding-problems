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

const int MOD = 998244353, N = 2e5 + 5;

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

vector<int> g[N];
int dep[N], par[N];
int traverse(int cur, int last, int d)
{
    par[cur] = last;
    dep[cur] = d;
    int mx = cur;
    for (int e : g[cur])
    {
        if (e != last)
        {
            int v = traverse(e, cur, d + 1);
            if (dep[v] > dep[mx])
                mx = v;
        }
    }
    return mx;
}

int dfs(int cur, int last, int dep, int req)
{
    if (g[cur].size() == 1 && g[cur][0] == last)
        if (dep == req)
            return 1;
    int sum = 0;
    for (int e : g[cur])
        if (e != last)
            sum += dfs(e, cur, dep + 1, req);
    return sum;
}

int solve()
{
    int n, u, v, res = 1;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    // find farthest node from root
    int root = traverse(1, -1, 1);
    // root is one end of diameter, find other end using same dfs
    int leaf = traverse(root, -1, 1);
    vector<int> nodes;
    while (leaf != -1)
    {
        nodes.pb(leaf);
        leaf = par[leaf];
    }
    int sz = nodes.size();
    int diam = sz - 1;
    int center = nodes[(sz - 1) / 2];
    if (diam & 1)
    {
        int c1 = nodes[(sz - 1) / 2], c2 = nodes[sz / 2];
        res = mul(dfs(c1, c2, 0, diam / 2), dfs(c2, c1, 0, diam / 2));
    }
    else
    {
        int cnt = 1;
        for (int e : g[center])
        {
            int sum = dfs(e, center, 1, diam / 2);
            cnt += sum;
            res = mul(res, sum + 1);
        }
        res = add(res, -cnt);
    }
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