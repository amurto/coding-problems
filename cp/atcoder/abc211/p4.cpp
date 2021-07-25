#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 3e5 + 1;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int solve()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> dis(n + 1, n + 5), ways(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dis[1] = 0;
    ways[1] = 1;
    queue<int> q;
    q.push(1);
    int d = 1;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            int cur = q.front();
            q.pop();
            for (int e : g[cur])
            {
                if (dis[e] >= d)
                {
                    ways[e] = add(ways[e], ways[cur]);
                    if (dis[e] > d)
                    {
                        dis[e] = d;
                        q.push(e);
                    }
                }
            }
        }
        d++;
    }
    return ways[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}