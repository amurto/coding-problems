#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 1e5 + 5;
vector<int> g[N];
int arr[N], sz[N], vis1[N], vis2[N], ver[N], dp[N];
map<int, int> mp;
int sum = 0;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int set_sz(int cur, int last, int t)
{
    vis1[cur] = vis2[cur] = t;
    ver[t] = cur;
    sz[cur] = 1;
    for (int e : g[cur])
    {
        if (e != last)
        {
            vis2[cur] = max(vis2[cur], set_sz(e, cur, vis2[cur] + 1));
            sz[cur] += sz[e];
        }
    }
    return vis2[cur];
}

void sack(int cur, int last, bool keep)
{
    int mx = -1, big = -1;
    if (g[cur].empty() || (g[cur].size() == 1 && g[cur][0] == last))
    {
        dp[cur] = 1;
        if (keep)
        {
            sum = add(sum, dp[cur]);
            mp[arr[cur]] = add(mp[arr[cur]], dp[cur]);
        }
        else
            sum = 0;
        return;
    }
    for (int e : g[cur])
        if (e != last && sz[e] > mx)
            mx = sz[e], big = e;
    for (int e : g[cur])
        if (e != last && e != big)
            sack(e, cur, false);
    if (big != -1)
        sack(big, cur, true);
    for (int e : g[cur])
    {
        if (e != last && e != big)
        {
            for (int i = vis1[e]; i <= vis2[e]; i++)
            {
                mp[arr[ver[i]]] = add(mp[arr[ver[i]]], dp[ver[i]]);
                sum = add(sum, dp[ver[i]]);
            }
        }
    }
    dp[cur] = add(sum, -mp[arr[cur]]);
    sum = add(sum, dp[cur]);
    mp[arr[cur]] = add(mp[arr[cur]], dp[cur]);
    if (!keep)
    {
        for (int i = vis1[cur]; i <= vis2[cur]; i++)
            mp[arr[ver[i]]] = add(mp[arr[ver[i]]], -dp[ver[i]]);
        sum = 0;
    }
}

int solve()
{
    int n, u, v;
    cin >> n;
    mp.clear();
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        dp[i] = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    set_sz(1, 1, 0);
    sack(1, 1, true);
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = add(res, dp[i]);
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