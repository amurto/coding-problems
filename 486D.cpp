// https://codeforces.com/contest/486/problem/D
// Valid Sets

#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 2005;
vector<int> g[N];

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

int dfs(vector<int> &arr, vector<bool> &vis, int cur, int last, int lim)
{
    if (vis[cur] || arr[cur] < lim)
        return 0;
    int w = 1;
    for (int e : g[cur])
        if (e != last)
            w = mul(w, add(dfs(arr, vis, e, cur, lim), 1));
    return w;
}

int solve()
{
    int d, n, u, v, res = 0;
    cin >> d >> n;
    vector<int> arr(n + 1), ord(n);
    vector<bool> vis(n + 1);
    iota(ord.begin(), ord.end(), 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(ord.begin(), ord.end(), [&](int &i1, int &i2)
         { return arr[i1] < arr[i2]; });
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = n - 1; i = 0; i--)
    {
        int cur = ord[i];
        cout << cur << "\n";
        d(cur);
        int lim = arr[cur] - d;
        int w = dfs(arr, vis, cur, cur, lim);
        res = add(res, w);
        vis[cur] = true;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}