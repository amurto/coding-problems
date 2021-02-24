#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 3e5 + 5;

vector<int> g[N];
int deg[N];

// Kahn's Algorithm
void toposort(int n)
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
        return;
    for (int e : order)
        cout << e << " ";
}

void solve()
{
    int n, m, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
        deg[i] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        deg[v]++;
    }
    toposort(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}