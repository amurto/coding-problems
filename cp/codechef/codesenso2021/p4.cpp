#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
vector<int> g[N];
int arr[N], sz[N], vis1[N], vis2[N], ver[N], pre[N], suf[N], sub_gcd[N];

int set_sz(int cur, int last, int t)
{
    vis1[cur] = vis2[cur] = t;
    ver[t] = cur;
    sz[cur] = 1;
    sub_gcd[cur] = arr[cur];
    for (int e : g[cur])
    {
        if (e != last)
        {
            vis2[cur] = max(vis2[cur], set_sz(e, cur, vis2[cur] + 1));
            sz[cur] += sz[e];
            sub_gcd[cur] = __gcd(sub_gcd[cur], sub_gcd[e]);
        }
    }
    return vis2[cur];
}

ll dfs(int cur, int last)
{
    ll res = 0;
    if (last != -1)
        res = __gcd(pre[vis1[cur] - 1], suf[vis2[cur] + 1]);
    for (int e : g[cur])
        if (e != last)
            res += 1ll * sub_gcd[e];
    for (int e : g[cur])
        if (e != last)
            res = max(res, dfs(e, cur));
    return res;
}

ll solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    set_sz(1, 1, 1);
    pre[0] = 0;
    suf[n + 1] = 0;
    for (int i = 1; i <= n; i++)
        pre[i] = __gcd(pre[i - 1], arr[ver[i]]);
    for (int i = n; i > 0; i--)
        suf[i] = __gcd(suf[i + 1], arr[ver[i]]);
    ll res = dfs(1, -1);
    return res;
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