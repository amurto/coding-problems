// https://codeforces.com/problemset/problem/129/B
// Students and Shoelaces

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    while (m-- > 0)
    {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<bool> vis(n + 1);
    int groups = 0;
    bool found = true;
    while (found)
    {
        vector<int> nodes;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] || g[i].empty())
                continue;
            int valid = 0;
            for (int edge : g[i])
                if (!vis[edge])
                    valid++;
            if (valid == 1)
                nodes.pb(i);
        }
        if (nodes.empty())
            break;
        for (int node : nodes)
            vis[node] = true;
        groups++;
    }
    cout << groups << "\n";
    return 0;
}