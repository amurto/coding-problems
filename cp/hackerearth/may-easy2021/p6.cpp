#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, u, v;
    cin >> n;
    vector<int> leaf(n + 1), cnt(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 1)
            leaf[i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int e : g[i])
            if (leaf[e])
                cnt[i]++;
        if (cnt[i] >= 2)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "SAFE\n" : cout << "UNSAFE\n";
    return 0;
}