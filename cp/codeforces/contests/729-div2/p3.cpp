#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

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

ll small_div(ll x)
{
    for (ll i = 2; i <= x; i++)
        if (x % i > 0)
            return i;
    return x + 1;
}

ll lcm(ll l, ll x)
{
    ll g = __gcd(l, x);
    return (l / g) * x;
}

int solve()
{
    ll n, sum = 0;
    cin >> n;
    ll l = 1, rem = n;
    for (ll i = 2; rem > 0; i++)
    {
        l = lcm(l, i);
        ll cnt = n / l;
        sum = add(sum, mul(i, rem - cnt));
        rem = cnt;
    }
    return sum;
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