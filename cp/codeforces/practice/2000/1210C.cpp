// https://codeforces.com/contest/1210/problem/C
// Kamil and Making a Stream

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 1e5 + 5;
vector<int> g[N];
ll bt[N];

ll add(ll x, ll y)
{
    x %= MOD;
    y %= MOD;
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

ll mul(ll x, ll y)
{
    x %= MOD;
    y %= MOD;
    return (x * y) % MOD;
}

ll dfs(map<ll, ll> tmp, int cur, int last)
{
    ll res = 0;
    map<ll, ll> mp;
    for (auto x : tmp)
        mp[__gcd(x.first, bt[cur])] += x.second;
    mp[bt[cur]]++;
    for (auto x : mp)
        res = add(res, mul(x.first, x.second));
    for (int e : g[cur])
        if (e != last)
            res = add(res, dfs(mp, e, cur));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    ll res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> bt[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    map<ll, ll> mp;
    cout << dfs(mp, 1, -1) << "\n";
    return 0;
}