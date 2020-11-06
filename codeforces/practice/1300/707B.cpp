// https://codeforces.com/problemset/problem/707/B
// Bakery

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, u, v, w;
    cin >> n >> m >> k;
    vector<bool> storage(n + 1);
    vector<vector<pair<int, int>>> g(n + 1);
    while (m-- > 0)
    {
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    while (k-- > 0)
    {
        cin >> u;
        storage[u] = true;
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (!storage[i])
            continue;
        for (pair<int, int> edge : g[i])
        {
            if (storage[edge.first])
                continue;
            if (ans == -1)
                ans = edge.second;
            else
                ans = min(ans, edge.second);
        }
    }
    cout << ans << "\n"; 
    return 0;
}