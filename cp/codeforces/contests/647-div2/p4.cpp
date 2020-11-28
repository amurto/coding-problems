#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<pair<int, int>> edge(m);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> topic(n + 1);
    vector<pair<int, int>> res;
    for (int i = 1; i <= n; i++)
    {
        cin >> topic[i];
        res.pb({topic[i], i});
    }
    for (pair<int, int> p : res)
    {
        unordered_set<int> SET;
        for (int edge : g[p.second])
            if (topic[edge] == topic[p.second])
            {
                cout << "-1\n";
                return;
            }
            else if (topic[edge] < topic[p.second])
                SET.insert(topic[edge]);
        if (SET.size() + 1 != topic[p.second])
        {
            cout << "-1\n";
            return;
        }
    }
    sort(res.begin(), res.end());
    for (pair<int, int> p : res)
        cout << p.second << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}