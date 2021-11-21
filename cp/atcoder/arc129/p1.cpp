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

ll calc(ll n, ll x)
{
    if (x == 0)
        return 0;
    ll res = 0;
    for (int b = 60; b >= 0; b--)
    {
        if (!((n >> b) & 1))
        {
            ll t = 1ll << b;
            if (t <= x)
                res += min((1ll << (b + 1)) - 1, x) - t + 1;
        }
    }
    res = x - res;
    return res;
}

ll solve()
{
    ll n, l, r;
    cin >> n >> l >> r;
    ll res = calc(n, r) - calc(n, l - 1);
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