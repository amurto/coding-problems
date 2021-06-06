#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, m, u, v, res = 0;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
    }
    for (int i = 1; i <= n; i++)
    {
        queue<int> q;
        vector<bool> vis(n + 1);
        q.push(i);
        vis[i] = true;
        res++;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz-- > 0)
            {
                int cur = q.front();
                q.pop();
                for (int e : g[cur])
                {
                    if (!vis[e])
                    {
                        vis[e] = true;
                        q.push(e);
                        res++;
                    }
                }
            }
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