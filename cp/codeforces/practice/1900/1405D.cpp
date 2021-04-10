// https://codeforces.com/contest/1405/problem/D
// Tree Tag

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
vector<int> g[N];
int dep[N];
int dfs(int cur, int last, int &diam)
{
    int mx = 0;
    for (int e : g[cur])
    {
        if (e != last)
        {
            dep[e] = dep[cur] + 1;
            int st = dfs(e, cur, diam);
            diam = max(diam, mx + st);
            mx = max(mx, st);
        }
    }
    return mx + 1;
}

string solve()
{
    int n, a, b, da, db, u, v;
    cin >> n >> a >> b >> da >> db;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        dep[i] = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int diam = 0;
    dfs(a, -1, diam);
    return (2 * da >= min(diam, db) || dep[b] <= da) ? "Alice" : "Bob";
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