#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll K = 35;
ll cnt_bits(ll n)
{
    ll b = 0;
    for (ll i = 0; i < K; i++)
        if ((n >> i) & 1ll)
            b++;
    return b;
}

ll solve()
{
    ll n, x, e = 0;
    bool f = false;
    cin >> n >> x;
    for (ll i = 0; i < K; i += 2)
    {
        if ((n >> i) & 1ll)
        {
            f = true;
            e |= (1ll << i);
            n ^= (1ll << i);
        }
    }
    if (e > x)
        return -1;
    for (ll i = 1; i < K; i += 2)
    {
        if ((n >> i) & 1ll)
        {
            ll tmp = (e | (1ll << i));
            if (tmp <= x)
            {
                e = tmp;
                n ^= (1ll << i);
            }
        }
    }
    ll b = cnt_bits(n);
    if (e == 0)
        return b;
    return 1ll + b;
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