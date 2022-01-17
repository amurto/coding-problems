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

const int N = 3e5 + 5;
int col[N], pos[N], subsum[N], cnt[2 * N];
bool vis[2 * N];
vector<int> g[N];
vector<pii> edges;

int get_id(pii edge)
{
    int id = lower_bound(edges.begin(), edges.end(), edge) - edges.begin();
    return id;
}

void dfs(int cur, int last, int black)
{
    subsum[cur] = col[cur];
    for (int e : g[cur])
    {
        if (e != last)
        {
            dfs(e, cur, black);
            subsum[cur] += subsum[e];
            cnt[get_id({cur, e})] = subsum[e];
        }
    }
    if (last >= 0)
    {
        int id = get_id({cur, last});
        cnt[id] = black - subsum[cur];
    }
}

void solve()
{
    int n, black = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> col[i];
        pos[i] = col[i];
        black += col[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        edges.pb({u, v});
        edges.pb({v, u});
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < 2 * n; i++)
    {
        cnt[i] = 0;
        vis[i] = false;
    }
    dfs(1, -1, black);
    int sz = (int)edges.size();
    queue<int> q;
    for (int i = 0; i < sz; i++)
    {
        if (col[edges[i].second] == 1)
        {
            vis[i] = true;
            pos[edges[i].first] = 1;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int u = edges[cur].first, v = edges[cur].second;
        for (int e : g[u])
        {
            if (e != v)
            {
                int id = get_id({e, cur});
                if (!vis[id] && cnt[id] >= 2)
                {
                    vis[id] = true;
                    pos[e] = 1;
                    q.push(id);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << pos[i] << " ";
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