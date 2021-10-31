// https://codeforces.com/contest/1338/problem/C
// Perfect Triples

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

ll solve()
{
    ll n;
    cin >> n;
    ll last = 1, l = 0, r = 0;
    for (ll i = 4; n >= last; i *= 4)
    {
        if (n < i)
        {
            l = last;
            r = i - 1;
        }
        last = i;
    }
    n -= l;
    ll m = n % 3, dv = n / 3;
    ll a = l + dv, b = 0, c = 0;
    for (ll i = 1, bit = 0; i <= a; i *= 4, bit += 2)
    {
        ll v = 0;
        v |= ((a >> bit) & 1);
        v |= (((a >> (bit + 1)) & 1) << 1);
        if (v > 0)
            v++;
        if (v > 3)
            v %= 3;
        b |= (v << bit);
    }
    c = a ^ b;
    array<ll, 3> arr{a, b, c};
    return arr[m];
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