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

ll calc1(ll l, ll r)
{
    while (__gcd(l, r) > 1)
        l++;
    return r - l;
}

ll calc2(ll l, ll r)
{
    while (__gcd(l, r) > 1)
        r--;
    return r - l;
}

ll solve()
{
    ll l, r, res = 0;
    cin >> l >> r;
    for (ll i = r; i > max(r - 10000ll, l); i--)
        res = max(res, calc1(l, i));
    for (ll i = l; i < min(l + 10000ll, r); i++)
        res = max(res, calc2(i, r));
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