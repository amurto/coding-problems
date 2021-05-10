// https://codeforces.com/contest/1385/problem/E
// Directing Edges

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 2e5 + 5;

vector<int> g[N];
int deg[N], ord[N];

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
    for (int i = 0; i < order.size(); i++)
        ord[order[i]] = i + 1;
    return true;
}

void solve()
{
    int n, m, t, u, v;
    cin >> n >> m;
    vector<pii> ue, de;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        deg[i] = ord[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t >> u >> v;
        if (t == 0)
            ue.pb({u, v});
        else
        {
            de.pb({u, v});
            g[u].pb(v);
            deg[v]++;
        }
    }
    if (!toposort(n))
    {
        cout << "NO\n";
        return;
    }
    for (pii e : ue)
    {
        if (ord[e.first] > ord[e.second])
            swap(e.first, e.second);
        de.pb(e);
    }
    cout << "YES\n";
    for (pii e : de)
        cout << e.first << " " << e.second << "\n";
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