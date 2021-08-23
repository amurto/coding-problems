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

const ll MOD = 998244353;

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

bool is_overflow(ll x, ll y, ll n)
{
    return x > (n / y);
}

ll num_odd(ll x)
{
    if (x == 0)
        return 0;
    return (x + 1) / 2;
}

ll num_even(ll x)
{
    if (x == 0)
        return 0;
    return x / 2;
}

ll solve()
{
    ll n, res = 0;
    cin >> n;
    for (ll i = 1; i * i <= n; i++)
    {
        ll low = i, high = n, mx = i;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (!is_overflow(i, mid, n))
            {
                mx = max(mx, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if (i & 1)
            res = add(res, num_odd(mx) - num_odd(i - 1));
        else
            res = add(res, num_even(mx) - num_even(i - 1));
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