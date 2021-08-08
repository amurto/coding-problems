#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void dfs(vector<vector<int>> &g, vector<int> &seq, int cur, int last)
{

    sort(g[cur].begin(), g[cur].end());
    seq.pb(cur);
    for (int e : g[cur])
    {
        if (e != last)
        {
            dfs(g, seq, e, cur);
            seq.pb(cur);
        }
    }
}

void solve()
{
    int n, u, v;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> seq;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(g, seq, 1, 1);
    for (int e : seq)
        cout << e << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}