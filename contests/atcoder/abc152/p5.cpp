#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MOD = 1000000007;

ll add(ll x, ll y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

// Binary Exponentiation O(logn)
// n^m mod p
// p is large prime number
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
    int n;
    cin >> n;
    vector<ll> arr(n), inv(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        inv[i] = power(arr[i], MOD-2, MOD);
    }
    ll lcm = arr[0];
    for (int i = 1; i < n; i++) {
        lcm = lcm * arr[i]/__gcd(lcm, arr[i]);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans = add(ans, mul(lcm , inv[i]));
    cout << ans << "\n";
    return 0;
}