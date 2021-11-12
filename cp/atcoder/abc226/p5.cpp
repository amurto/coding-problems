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

const int MOD = 998244353, N = 2e5 + 5;
vector<int> g[N], nodes;
int vis[N];

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

void dfs(int cur)
{
    nodes.pb(cur);
    vis[cur] = true;
    for (int e : g[cur])
        if (!vis[e])
            dfs(e);
}

int solve()
{
    int n, m, res = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        vis[i] = false;
    vector<int> deg(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            set<int> st(nodes.begin(), nodes.end());
            int len = (int)nodes.size(), sum = 0;
            for (int x : nodes)
                sum += deg[x];
            sum /= 2;
            if (sum < len)
                return 0;
            queue<int> q;
            for (int x : nodes)
            {
                if (deg[x] == 1)
                {
                    st.erase(x);
                    q.push(x);
                }
            }
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (int e : g[cur])
                {
                    if (st.find(e) != st.end())
                    {
                        deg[e]--;
                        if (deg[e] == 1)
                        {
                            st.erase(e);
                            q.push(e);
                        }
                    }
                }
            }
            for (int x : st)
                if (deg[x] != 2)
                    return 0;
            res = mul(res, 2);
            nodes.clear();
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}