// https://codeforces.com/contest/1100/problem/E
// Andrew and Taxi

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 1e5 + 5;
vector<int> g[N];
int deg[N], ord[N];

class edge
{
public:
    int u, v, w, id;
    edge() {}
    edge(int u, int v, int w, int id) : u(u), v(v), w(w), id(id) {}
    bool operator<(const edge &other) const
    {
        return w > other.w;
    }
};

// Kahn's Algorithm
bool toposort(int n)
{
    queue<int> q;
    vector<int> order;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.push(i);
    int cnt = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int e : g[cur])
            if (--deg[e] == 0)
                q.push(e);
        order.pb(cur);
        cnt++;
    }
    if (cnt != n)
        return false;
    for (int i = 0; i < n; i++)
        ord[order[i]] = i + 1;
    return true;
}

void clear_graph(int n)
{
    for (int i = 1; i <= n; i++)
    {
        deg[i] = ord[i] = 0;
        g[i].clear();
    }
}

bool check_graph(vector<edge> &edges, int mid, int n)
{
    clear_graph(n);
    for (int i = 0; i <= mid; i++)
    {
        g[edges[i].u].pb(edges[i].v);
        deg[edges[i].v]++;
    }
    return toposort(n);
}
void solve()
{
    int n, m, u, v, w, mx = 0;
    cin >> n >> m;
    vector<int> ids;
    vector<edge> edges;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edges.pb(edge(u, v, w, i));
    }
    sort(edges.begin(), edges.end());
    int low = 0, high = m - 1, res = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check_graph(edges, mid, n))
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    check_graph(edges, res, n);
    for (int i = res + 1; i < m; i++)
    {
        mx = max(mx, edges[i].w);
        if (ord[edges[i].u] > ord[edges[i].v])
            ids.pb(edges[i].id);
    }
    sort(ids.begin(), ids.end());
    cout << mx << " ";
    cout << (int)ids.size() << "\n";
    for (int id : ids)
        cout << id + 1 << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}