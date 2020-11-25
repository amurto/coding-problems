#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n, u, v;
    cin >> n;
    vector<set<int>> g(n + 1);
    vector<int> cnt(n + 1, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    queue<int> leaf;
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 1)
            leaf.push(i);

    while (!leaf.empty())
    {
        int cur = leaf.front();
        leaf.pop();
        int parent = *g[cur].begin();
        cnt[parent] += cnt[cur];
        cnt[cur] = 0;
        g[parent].erase(cur);
        if (g[parent].size() == 1)
            leaf.push(parent);
    }

    ll paths = 0;
    for (int i = 1; i <= n; i++)
    {
        paths += cnt[i] * 1ll * (cnt[i] - 1) / 2;
        paths += cnt[i] * 1ll * (n - cnt[i]);
    }
    return paths;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}