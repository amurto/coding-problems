// https://codeforces.com/contest/688/problem/C
// NP-Hard Problem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 1;
vector<int> c(N + 1);
vector<vector<int>> g(N + 1), ds(2);
bool bfs(int src)
{
    queue<int> q;
    q.push(src);
    c[src] = 0;
    ds[0].pb(src);
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            int cur = q.front();
            q.pop();
            for (int e : g[cur])
            {
                if (c[e] == c[cur])
                    return false;
                if (c[e] < 0)
                {
                    c[e] = c[cur] ^ 1;
                    ds[c[e]].pb(e);
                    q.push(e);
                }
            }
        }
    }
    return true;
}
void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        c[i] = -1;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    bool pos = true;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] < 0)
            pos = bfs(i);
        if (!pos)
        {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < ds.size(); i++)
    {
        cout << ds[i].size() << "\n";
        for (int e : ds[i])
            cout << e << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}