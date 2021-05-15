// https://codeforces.com/contest/1280/problem/C
// Jeremy Bearimy

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 2e5 + 5;
vector<pii> g[N];

int dfs(ll &mn, ll &mx, int cur, int last, int k)
{
    int sum = 1;
    for (pii e : g[cur])
    {
        if (e.first != last)
        {
            int c = dfs(mn, mx, e.first, cur, k);
            if (c & 1)
                mn += 1ll * e.second;
            mx += 1ll * min(c, k - c) * e.second;
            sum += c;
        }
    }
    return sum;
}

void solve()
{
    int k, u, v, w;
    cin >> k;
    for (int i = 1; i <= 2 * k; i++)
        g[i].clear();
    for (int i = 0; i < 2 * k - 1; i++)
    {
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    ll mn = 0, mx = 0;
    dfs(mn, mx, 1, 1, 2 * k);
    cout << mn << " " << mx << "\n";
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