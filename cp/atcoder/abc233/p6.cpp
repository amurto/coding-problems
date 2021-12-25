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

const int N = 1005;
vector<int> g[N], gt[N];

void dfs1(vector<int> &nodes, vector<bool> &vis, int cur, int last)
{
    nodes.pb(cur);
    vis[cur] = true;
    for (int e : g[cur])
    {
        if (!vis[e])
        {
            gt[cur].pb(e);
            gt[e].pb(cur);
            dfs1(nodes, vis, e, cur);
        }
    }
}

bool dfs2(vector<int> &path, vector<bool> &vis, int cur, int last, int des)
{
    if (cur == des)
        return true;
    bool ans = false;
    for (int e : gt[cur])
    {
        if (!ans && e != last && !vis[e])
        {
            ans = dfs2(path, vis, e, cur, des);
            if (ans)
                path.pb(e);
        }
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n;
    vector<int> perm(n + 1), deg(n + 1), res;
    vector<vector<int>> ids(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        cin >> perm[i];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ids[a][b] = ids[b][a] = i + 1;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<bool> vis(n + 1), fixed(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vector<int> nodes;
            dfs1(nodes, vis, i, i);
            for (int x : nodes)
                deg[x] = (int)gt[x].size();
            queue<int> q;
            for (int x : nodes)
                if (deg[x] <= 1)
                    q.push(x);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (int e : gt[cur])
                    if (!fixed[e] && --deg[e] <= 1)
                        q.push(e);
                if (perm[cur] != cur)
                {
                    int pos = -1;
                    for (int i = 1; i <= n; i++)
                        if (perm[i] == cur)
                            pos = i;
                    vector<int> path;
                    bool ans = dfs2(path, fixed, cur, cur, pos);
                    path.pb(cur);
                    if (!ans)
                    {
                        cout << "-1\n";
                        return;
                    }
                    int len = (int)path.size();
                    for (int i = 1; i < len; i++)
                    {
                        swap(perm[path[i - 1]], perm[path[i]]);
                        res.pb(ids[path[i - 1]][path[i]]);
                    }
                }
                fixed[cur] = true;
            }
        }
    }
    cout << (int)res.size() << "\n";
    for (int id : res)
        cout << id << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}