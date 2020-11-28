#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    ll level = 1, res = 1;
    vector<bool> vis(n + 1);
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int size = q.size();
        while (size-- > 0)
        {
            int parent = q.front();
            q.pop();
            vis[parent] = true;
            for (int child : tree[parent])
            {
                if (vis[child])
                    continue;
                q.push(child);
            }
        }
        level++;
        res += q.size() * level;
    }
    cout << res << "\n";
    return 0;
}