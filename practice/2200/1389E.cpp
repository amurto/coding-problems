// https://codeforces.com/contest/1389/problem/E
// Calendar Ambiguity

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

ll ap_sum(ll a, ll diff, ll n)
{
    return (n * (2 * a + (n - 1) * diff)) / 2;
}

ll solve()
{
    ll m, k, w;
    cin >> m >> k >> w;
    ll x = w / __gcd(k - 1, w);
    ll mx = min(m, k) - x;
    ll n = (mx + x - 1) / x;
    return ap_sum(mx, -x, n);
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