// https://codeforces.com/contest/1238/problem/F
// The Maximum Subtree

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

const int N = 3e5 + 5;
vector<int> g[N];
int sub[N];
int precompute(int cur, int last)
{
    int mx = 0;
    for (int e : g[cur])
        if (e != last)
            mx = max(mx, precompute(e, cur));
    int sz = (int)g[cur].size();
    if (last)
        sz--;
    sub[cur] = 1 + mx + sz - (sz > 0);
    return sub[cur];
}

int dfs(int cur, int last, int par_tree)
{
    int sz = (int)g[cur].size(), res = 0;
    vector<int> children(sz);
    for (int i = 0; i < sz; i++)
        if (g[cur][i] == last)
            children[i] = par_tree;
        else
            children[i] = sub[g[cur][i]];
    array<int, 2> cnt{0, 0};
    for (int c : children)
    {
        if (c > cnt[1])
            cnt[1] = c;
        if (cnt[1] > cnt[0])
            swap(cnt[0], cnt[1]);
    }
    if (sz == 1)
        res = max(res, 1 + cnt[0]);
    else
        res = max(res, 1 + cnt[0] + cnt[1] + sz - 2);
    for (int e : g[cur])
        if (e != last)
            if (sub[e] == cnt[0])
                res = max(res, dfs(e, cur, cnt[1] + 1));
            else
                res = max(res, dfs(e, cur, cnt[0] + 1));
    return res;
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
    precompute(1, 0);
    return dfs(1, 0, 0);
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