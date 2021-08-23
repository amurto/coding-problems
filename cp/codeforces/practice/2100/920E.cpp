// https://codeforces.com/contest/920/problem/E
// Connected Components?

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
set<int> g[N];

void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<int> res;
    vector<bool> vis(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    while (!st.empty())
    {
        int nodes = st.size();
        int cur = *st.begin();
        int sz = g[cur].size();
        vector<int> rem;
        rem.pb(cur);
        for (int x : st)
            if (!g[cur].count(x))
                rem.pb(x);
        for (int i = 0; i < rem.size(); i++)
        {
            vis[rem[i]] = true;
            vector<int> del;
            for (int x : g[cur])
                if (!g[rem[i]].count(x))
                    del.pb(x);
            for (int e : del)
            {
                g[cur].erase(e);
                rem.pb(e);
            }
        }
        for (int x : g[cur])
        {
            vector<int> del;
            for (int e : g[x])
                if (vis[e])
                    del.pb(e);
            for (int dd : del)
                g[x].erase(dd);
        }
        swap(st, g[cur]);
        int nsz = (int)st.size();
        res.pb(nodes - nsz);
    }
    cout << res.size() << "\n";
    sort(res.begin(), res.end());
    for (int r : res)
        cout << r << " ";
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