// https://codeforces.com/contest/1364/problem/D
// Ehab's Last Corollary

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

const int N = 1e5 + 5;
vector<int> g[N];
int col[N], par[N];

int dfs(vector<int> &cnt, int req, int cur, int last, int c, int &l, int &r)
{
    par[cur] = last;
    col[cur] = c;
    for (int e : g[cur])
    {
        if (col[e] == col[cur])
        {
            l = e;
            r = cur;
            return 1;
        }
    }
    cnt[c]++;
    if (max(cnt[0], cnt[1]) >= req)
        return 1;
    for (int e : g[cur])
        if (col[e] == -1 && dfs(cnt, req, e, cur, c ^ 1, l, r) == 1)
            return 1;
    return 0;
}

void solve()
{
    int n, m, k, u, v, res = 0, l = 0, r = 0;
    cin >> n >> m >> k;
    int req = (k + 1) / 2;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
    {
        col[i] = -1;
        par[i] = i;
    }
    vector<int> cnt(2);
    dfs(cnt, req, 1, 1, 0, l, r);
    if (max(cnt[0], cnt[1]) >= req)
        res = 1;
    if (res)
    {
        int c = 0;
        if (cnt[1] >= cnt[c])
            c = 1;
        vector<int> ind_set;
        for (int i = 1; i <= n; i++)
            if (col[i] == c)
                ind_set.pb(i);
        cout << 1 << "\n";
        for (int i : ind_set)
            cout << i << " ";
        cout << "\n";
        return;
    }
    cout << 2 << "\n";
    vector<int> cycle;
    int cur = r;
    while (cur != l)
    {
        cycle.pb(cur);
        cur = par[cur];
    }
    cycle.pb(l);
    cout << cycle.size() << "\n";
    for (int i : cycle)
        cout << i << " ";
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