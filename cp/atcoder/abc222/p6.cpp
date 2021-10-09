#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;
#define pb push_back

const int N = 2e5 + 5;
vector<pii> g[N];

ll D[N], sub[N], res[N];

ll precompute(int cur, int last)
{
    sub[cur] = 0;
    for (pii e : g[cur])
        if (e.first != last)
            sub[cur] = max(sub[cur], precompute(e.first, cur) + e.second);
    return max(D[cur], sub[cur]);
}

void dfs(int cur, int last, ll par)
{
    res[cur] = max(sub[cur], par);
    array<ll, 2> mx{max(par, D[cur]), min(par, D[cur])};
    for (pii e : g[cur])
    {
        if (e.first != last)
        {
            ll v = max(sub[e.first], D[e.first]) + e.second;
            if (v > mx[1])
                mx[1] = v;
        }
        if (mx[1] > mx[0])
            swap(mx[0], mx[1]);
    }
    for (pii e : g[cur])
    {
        if (e.first != last)
        {
            if (max(sub[e.first], D[e.first]) + e.second == mx[0])
                dfs(e.first, cur, mx[1] + e.second);
            else
                dfs(e.first, cur, mx[0] + e.second);
        }
    }
}

void solve()
{
    int n, u, v;
    ll c;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> c;
        g[u].pb({v, c});
        g[v].pb({u, c});
    }
    for (int i = 1; i <= n; i++)
        cin >> D[i];
    precompute(1, 1);
    dfs(1, 1, 0);
    for (int i = 1; i <= n; i++)
        cout << res[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}