// https://codeforces.com/contest/1068/problem/C
// Colored Rooks

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 101;
vector<bool> vis(N);
vector<vector<pair<int, int>>> res(N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        vis[u] = vis[v] = true;
        res[u].pb({u, i});
        res[v].pb({v, i});
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            res[i].pb({i, ++m});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << res[i].size() << "\n";
        for (pair<int, int> p : res[i])
            cout << p.first << " " << p.second << "\n";
    }
    return 0;
}