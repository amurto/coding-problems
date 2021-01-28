// https://codeforces.com/contest/476/problem/C
// Dreamoon and Sums

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MOD = 1e9 + 7;

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

// Binary Exponentiation O(logn)
// n^m mod p
ll power(ll n, ll m, ll p)
{
    ll res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b, res = 0;
    cin >> a >> b;
    for (ll m = 1; m < b; m++)
    {
        ll l = add(mul(b, m), m);
        res = add(res, mul(a, add(mul(2, l), mul(a - 1, mul(m, b)))));
        res %= MOD;
    }
    cout << mul(res, power(2, MOD - 2, MOD)) << "\n";
    return 0;
}