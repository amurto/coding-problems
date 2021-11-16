// Find Bridges in a graph in O(n+m)
// https://cp-algorithms.com/graph/bridge-searching.html

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class edge
{
public:
    int u, v, id;
    ll w;
    edge() {}
    edge(int u, int v, ll w, int id) : u(u), v(v), w(w), id(id) {}
    bool operator<(const edge &other) const
    {
        return w < other.w;
    }
};

const int N = 2e5 + 5;
vector<edge> g[N];

vector<int> find_bridges(int n)
{
    vector<int> bin(n + 1), bout(n + 1), mn_time(n + 1), bridge_ids;
    vector<bool> b_vis(n + 1);
    auto preorder_dfs = [&](const auto &self, int cur, int par, int t) -> int
    {
        bin[cur] = bout[cur] = mn_time[cur] = t;
        b_vis[cur] = true;
        for (edge e : g[cur])
        {
            if (!b_vis[e.v])
            {
                bout[cur] = self(self, e.v, cur, bout[cur] + 1);
                mn_time[cur] = min(mn_time[cur], mn_time[e.v]);
                // check for bridge
                if (mn_time[e.v] > bin[cur])
                    bridge_ids.pb(e.id);
            }
            else if (e.v != par)
                mn_time[cur] = min(mn_time[cur], bin[e.v]);
        }
        return bout[cur];
    };
    for (int i = 1; i <= n; i++)
        if (!b_vis[i])
            preorder_dfs(preorder_dfs, i, -1, 1);
    return bridge_ids;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(edge(u, v, 0, i));
        g[v].pb(edge(v, u, 0, i));
    }
    vector<int> bridge_ids = find_bridges(n);
    return 0;
}