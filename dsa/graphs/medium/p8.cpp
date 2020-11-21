// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/pilgrims-and-portals/
// Pilgrims and Portals

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m, k, u, v, w;
        cin >> n >> m >> k;
        vector<vector<pair<int, int>>> g(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            g[u].pb({v, w});
            g[v].pb({u, w});
        }
        
    }
    return 0;
}