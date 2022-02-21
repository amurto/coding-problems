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

bool is_irrelevant(char c1, int x1, char c2, int x2)
{
    if (c1 == c2)
        return false;
    if (c1 == 'R')
        swap(x1, x2);
    return x1 < x2;
}

bool is_destined(char c1, int x1, char c2, int x2)
{
    if (c1 == c2)
        return false;
    if (c1 == 'L')
        swap(x1, x2);
    return x1 < x2;
}

char flip(char ch)
{
    if (ch == 'L')
        return 'R';
    return 'L';
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<bool> vis(n + 1);
    string c(n + 1, 'L');
    vector<int> pos(n + 1), t(m), u(m), v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> t[i] >> u[i] >> v[i];
        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (int e : g[cur])
                {
                    if (vis[e])
                    {
                        if (c[cur] == c[e])
                        {
                            cout << "NO\n";
                            return;
                        }
                    }
                    else
                    {
                        c[e] = flip(c[cur]);
                        vis[e] = true;
                        q.push(e);
                    }
                }
            }
        }
    }
    vector<int> ids, deg(n + 1);
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < m; i++)
    {
        if (t[i] == 1)
        {
            if (c[u[i]] == 'R')
                swap(u[i], v[i]);
        }
        else
        {
            if (c[u[i]] == 'L')
                swap(u[i], v[i]);
        }
        g[u[i]].pb(v[i]);
        deg[v[i]]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int cur = q.front();
        ids.pb(cur);
        q.pop();
        for (int e : g[cur])
            if (--deg[e] == 0)
                q.push(e);
    }
    if ((int)ids.size() < n)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; i++)
        pos[ids[i]] = i;
    for (int i = 0; i < m; i++)
    {
        if (t[i] == 1)
        {
            if (!is_irrelevant(c[u[i]], pos[u[i]], c[v[i]], pos[v[i]]))
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            if (!is_destined(c[u[i]], pos[u[i]], c[v[i]], pos[v[i]]))
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << c[i] << " " << pos[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}