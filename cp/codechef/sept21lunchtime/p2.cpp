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

void solve()
{
    ll n, a = 0, b = 0;
    cin >> n;
    if (n % 2 == 0)
    {
        a = 2 * n;
        b = n;
    }
    for (ll i = 3; a == 0 && i < 100; i += 2)
    {
        if (__gcd(n, i) == 1)
        {
            a = n * i;
            b = n * (i - 1);
        }
    }
    cout << a << " " << b << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}