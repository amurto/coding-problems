#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 21;
vector<int> g[N];

ll circle_dfs(vector<int> &col, int cur, int k, int n)
{
    set<int> st;
    for (int i = 1; i <= 3; i++)
        st.insert(i);
    st.erase(k);
    if (cur == n - 1)
    {
        st.erase(col[0]);
        ll sz = st.size();
        return sz;
    }
    ll w = 0;
    for (int c : st)
    {
        col[cur] = c;
        w += circle_dfs(col, cur + 1, c, n);
        col[cur] = 0;
    }
    return w;
}

ll dfs2(vector<int> &col, int cur, int k, int n)
{
    set<int> st;
    for (int i = 1; i <= 3; i++)
        st.insert(i);
    st.erase(k);
    if (cur == n)
        return 1ll;
    ll w = 0;
    for (int c : st)
    {
        col[cur] = c;
        w += dfs2(col, cur + 1, c, n);
        col[cur] = 0;
    }
    return w;
}

int lin_dfs(vector<bool> &vis, int cur, int last)
{
    vis[cur] = true;
    int cnt = 1;
    for (int e : g[cur])
        if (e != last && !vis[e])
            cnt += lin_dfs(vis, e, cur);
    return cnt;
}

ll solve()
{
    int n, m, u, v;
    cin >> n >> m;
    ll ways = 1;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        if (g[i].size() > 2)
            return 0;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && g[i].size() < 2)
        {
            int sz = lin_dfs(vis, i, 0);
            vector<int> col(sz);
            ways *= dfs2(col, 0, 0, sz);
        }
    }
    vector<int> col(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int sz = lin_dfs(vis, i, g[i][1]);
            cout << sz << "\n";
            vector<int> col(sz);
            ways *= circle_dfs(col, 0, 0, sz);
        }
    }
    return ways;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // for (int i = 1; i <= 10; i++)
    // {
    //     vector<int> col(i);
    //     cout << dfs2(col, 0, 0, i) << "\n";
    // }
    cout << solve() << "\n";
    return 0;
}