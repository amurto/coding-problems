// https://codeforces.com/contest/618/problem/D
// Hamiltonian Spanning Tree

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

int dfs(int cur, int last, int &roads)
{
    int chains = 0;
    for (int e : g[cur])
        if (e != last)
            chains += dfs(e, cur, roads);
    roads += max(0, chains - 1);
    return chains >= 2 ? 0 : 1;
}

ll solve()
{
    int n, u, v, roads = -1;
    ll x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (x >= y)
    {
        for (int i = 1; i <= n; i++)
            if (g[i].size() == n - 1)
                return x + y * (n - 2);
        return y * (n - 1);
    }
    roads += dfs(1, 1, roads);
    return y * roads + x * (n - 1 - roads);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}