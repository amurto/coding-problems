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

ll nc2(int v)
{
    return (v * 1ll * (v - 1));
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> deg(n + 1);
    vector<pii> edges;
    ll cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.pb({u, v});
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1; i <= n; i++)
        cnt += nc2(deg[i]);
    cout << cnt / 2 + n - 1 << "\n";
    for (int i = 0; i < q; i++)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        ll tmp = cnt;
        tmp -= nc2(deg[a]);
        tmp -= nc2(deg[b]);
        tmp -= nc2(deg[x]);
        tmp -= nc2(deg[y]);
        deg[a]--;
        deg[b]--;
        deg[x]++;
        deg[y]++;
        tmp += nc2(deg[a]);
        tmp += nc2(deg[b]);
        tmp += nc2(deg[x]);
        tmp += nc2(deg[y]);
        cout << tmp / 2 + n - 1 << "\n";
        deg[a]++;
        deg[b]++;
        deg[x]--;
        deg[y]--;
    }
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