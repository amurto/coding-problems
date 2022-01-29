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

ll getcount(ll n, int k)
{
    ll res = (n >> (k + 1)) << k;
    if ((n >> k) & 1)
        res += n & ((1ll << k) - 1);
    return res;
}

ll solve()
{
    ll n, res = 0;
    cin >> n;
    for (int bit = 30; bit >= 0; bit--)
    {
        ll cnt = getcount(n + 1, bit);
        res += (min(n - cnt, cnt) * (1ll << bit) * 2);
    }
    return res;
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