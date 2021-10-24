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

int solve()
{
    int n = 9, m, dis = 1;
    cin >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    string st(n, '0');
    for (int i = 1; i <= n - 1; i++)
    {
        int p;
        cin >> p;
        st[p - 1] = char(i + '0');
    }
    string t = "123456780";
    if (st == t)
        return 0;
    set<string> vis;
    vis.insert(st);
    queue<string> q;
    q.push(st);
    while (!q.empty())
    {
        int sz = q.size();
        while (sz > 0)
        {
            string cur = q.front();
            q.pop();
            int id = 0;
            for (int i = 0; i < n; i++)
                if (cur[i] == '0')
                    id = i + 1;
            for (int e : g[id])
            {
                string tmp = cur;
                swap(tmp[id - 1], tmp[e - 1]);
                if (tmp == t)
                    return dis;
                if (vis.find(tmp) == vis.end())
                {
                    vis.insert(tmp);
                    q.push(tmp);
                }
            }
            sz--;
        }
        dis++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}