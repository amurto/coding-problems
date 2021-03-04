// https://codeforces.com/contest/1033/problem/D
// Divisors

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MOD = 998244353;

ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

ll sq_root(ll x)
{
    ll l = 0, r = 2e9 + 1;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    if (l * l == x)
        return l;
    return 0;
}

ll cube_root(ll x)
{
    ll l = 0, r = 1259922;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    if (l * l * l == x)
        return l;
    return 0;
}

ll quad_root(ll x)
{
    ll l = 0, r = 37607;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid * mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    if (l * l * l * l == x)
        return l;
    return 0;
}

bool fac(map<ll, ll> &mp, ll x, ll y)
{
    ll g = __gcd(x, y);
    if (g == 1 || g == x)
        return false;
    mp[g]++;
    x /= g;
    if (x > 1)
        mp[x]++;
    return true;
}

ll solve()
{
    int n;
    cin >> n;
    ll res = 1;
    map<ll, ll> mp;
    vector<ll> arr(n);
    vector<vector<ll>> st(n, vector<ll>(3));
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
            continue;
        st[i][0] = sq_root(arr[i]);
        st[i][1] = cube_root(arr[i]);
        st[i][2] = quad_root(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        for (int j = 2; j >= 0; j--)
        {
            if (st[i][j] > 0)
            {
                mp[st[i][j]] += j + 2;
                break;
            }
        }
        if (st[i][0] > 0 || st[i][1] > 0 || st[i][2] > 0)
            continue;
        bool f = false;
        for (int j = 0; !f && j < n; j++)
        {
            if (i == j || arr[j] == 1)
                continue;
            if (fac(mp, arr[i], arr[j]))
                f = true;
        }
        if (f)
            continue;
        ll cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cnt++;
                vis[j] = true;
            }
        }
        res = mul(res, mul(cnt + 1, cnt + 1));
    }
    for (auto x : mp)
        res = mul(res, x.second + 1);
    return res;
}

int main()
{
    cout << solve() << "\n";
    fflush(stdout);
    return 0;
}