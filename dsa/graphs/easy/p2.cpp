// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/friendless-dr-sheldon-cooper-14/
// Friendless Dr. Sheldon Cooper

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
        int a, b, u, v, cost = -1;
        cin >> a >> b;
        vector<vector<int>> g(a + 1);
        for (int i = 0; i < b; i++)
        {
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        queue<int> q;
        vector<bool> vis(a + 1);
        q.push(1);
        while (!q.empty())
        {
            int from = q.front();
            q.pop();
            if (vis[from])
                continue;
            vis[from] = true;
            cost++;
            for (int to : g[from])
                if (!vis[to])
                    q.push(to);
        }
        cout << cost << "\n";
    }
    return 0;
}