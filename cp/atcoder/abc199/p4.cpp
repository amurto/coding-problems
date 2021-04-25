#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 21;
vector<int> g[N];

int dfs(vector<int> &comp, vector<bool> &vis, int cur)
{
    vis[cur] = true;
    comp.pb(cur);
    int cnt = 1;
    for (int e : g[cur])
        if (!vis[e])
            cnt += dfs(comp, vis, e);
    return cnt;
}

ll rgb(vector<int> &comp, vector<int> &col, int cur)
{
    if (cur == comp.size())
        return 1;
    ll w = 0;
    set<int> st;
    for (int i = 1; i <= 3; i++)
        st.insert(i);
    for (int e : g[comp[cur]])
        st.erase(col[e]);
    for (int c : st)
    {
        col[comp[cur]] = c;
        w += rgb(comp, col, cur + 1);
        col[comp[cur]] = 0;
    }
    return w;
}
ll solve()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<bool> vis(n + 1);
    vector<int> col(n + 1);
    ll ways = 1;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        vector<int> comp;
        int sz = dfs(comp, vis, i);
        ways *= rgb(comp, col, 0);
    }
    return ways;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}