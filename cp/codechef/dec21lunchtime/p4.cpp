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
int par[N], col[N], st[N][2];

int query(int x)
{
    cout << x << endl;
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

void dfs1(int cur, int last, int &t)
{
    par[cur] = last;
    st[cur][0] = st[cur][1] = 0;
    for (int e : g[cur])
        if (e != last)
            dfs1(e, cur, t);
    if (last > 0)
    {
        int ans = query(cur);
        if (t + st[cur][0] - st[cur][1] < ans)
        {
            st[par[cur]][1]++;
            col[cur] = 1;
        }
        else
        {
            st[par[cur]][0]++;
            col[cur] = 0;
        }
        for (int e : g[cur])
            if (e != last)
                col[e] ^= 1;
        swap(st[cur][0], st[cur][1]);
        t = ans;
    }
}

void dfs2(int cur, int last)
{
    if (cur == 1)
        col[cur] = 0;
    else
        col[cur] ^= col[par[cur]];
    for (int e : g[cur])
        if (e != last)
            dfs2(e, cur);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        col[i] = 0;
        g[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int t = query(1);
    dfs1(1, -1, t);
    dfs2(1, -1);
    array<int, 2> cnt{0, 0};
    int mn = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt[col[i]]++;
        if (cnt[0] < cnt[1])
            mn = 0;
        else
            mn = 1;
    }
    for (int i = 1; i <= n; i++)
        if (col[i] == mn)
            query(i);
    int ans = query(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}