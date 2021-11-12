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

const int N = 2e5 + 5, B = 18;
vector<int> g[N];
int dep[N];
int hp(int x)
{
    int v = -1;
    while (x > 0)
    {
        x >>= 1;
        v++;
    }
    return v;
}

void dfs(int cur, int last, int par)
{
    dep[cur] = par;
    for (int e : g[cur])
        if (e != last)
            dfs(e, cur, par ^ 1);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
    dfs(1, 1, 0);
    array<int, 2> cnt{0, 0};

    for (int i = 1; i <= n; i++)
        cnt[dep[i]]++;
    int mn = 0;
    if (cnt[0] > cnt[1])
        mn = 1;
    set<int> vis;
    for (int i = 1; i <= n; i++)
        vis.insert(i);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        int u = 1 << hp(i);
        if ((cnt[mn] & u) > 0)
            st.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dep[i] == mn)
        {
            p[i] = st.top();
            st.pop();
            vis.erase(p[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 0)
        {
            p[i] = *vis.begin();
            vis.erase(vis.begin());
        }
    }
    for (int i = 1; i <= n; i++)
        cout << p[i] << " ";
    cout << "\n";
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