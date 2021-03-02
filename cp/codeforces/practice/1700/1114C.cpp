// https://codeforces.com/contest/1114/problem/C
// Trailing Loves (or L'oeufs?)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void fac(map<ll, ll> &mp, ll b)
{
    for (ll i = 2; i * i <= b; i++)
    {
        if (b % i == 0)
        {
            ll cnt = 0;
            while (b % i == 0)
            {
                b /= i;
                cnt++;
            }
            mp[i] = cnt;
        }
    }
    if (b > 1)
        mp[b] = 1;
}

// power of p in n!
ll cnt(ll n, ll p)
{
    ll res = 0;
    while (n > 1)
    {
        res += (n / p);
        n /= p;
    }
    return res;
}

ll solve()
{
    ll n, b, x = 0, res = 1e18;
    cin >> n >> b;
    map<ll, ll> mp;
    fac(mp, b);
    for (auto p : mp)
        res = min(res, cnt(n, p.first) / p.second);
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