// https://codeforces.com/contest/837/problem/E
// Vasya's Function

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

multiset<ll> factorize(ll x)
{
    multiset<ll> ms;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
            {
                ms.insert(i);
                x /= i;
            }
        }
    }
    if (x > 1)
        ms.insert(x);
    return ms;
}

ll solve()
{
    ll a, b, g = 1, res = 0;
    cin >> a >> b;
    multiset<ll> ms = factorize(a);
    while (b > 0)
    {
        ll mx = 0, e = 0;
        for (ll x : ms)
        {
            ll v = b / (g * x);
            v = v * g * x;
            if (v >= mx)
            {
                mx = v;
                e = x;
            }
        }
        res += (b - mx) / g;
        g *= e;
        if (e > 0)
            ms.erase(ms.lower_bound(e));
        b = mx;
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