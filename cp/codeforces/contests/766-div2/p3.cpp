#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 1e5 + 5;
vector<pii> g[N];

void dfs(vector<int> &res, int cur, int last, int val)
{
    for (pii e : g[cur])
    {
        if (e.first != last)
        {
            res[e.second] = val;
            dfs(res, e.first, cur, val ^ 1);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    vector<int> deg(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] >= 3)
        {
            cout << "-1\n";
            return;
        }
    }
    vector<int> res(n - 1);
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 1)
        {
            dfs(res, i, -1, 0);
            break;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (res[i] == 0)
            res[i] = 2;
        else
            res[i] = 5;
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}