// https://codeforces.com/contest/1278/problem/E
// Tests for problem D

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

const int N = 5e5 + 5;
vector<int> g[N];
int L[N], R[N];

int dfs(int cur, int last, int l)
{
    for (int e : g[cur])
        if (e != last)
            L[e] = l++;
    R[cur] = l;
    reverse(g[cur].begin(), g[cur].end());
    for (int e : g[cur])
        if (e != last)
            l = dfs(e, cur, l + 1);
    return l;
}

void solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    L[1] = 1;
    dfs(1, 1, 2);
    for (int i = 1; i <= n; i++)
        cout << L[i] << " " << R[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}