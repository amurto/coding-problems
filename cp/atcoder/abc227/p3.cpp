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
    ll n, res = 0;
    cin >> n;
    for (ll a = 1; a <= min(n, 5000LL); a++)
    {
        for (ll j = a * a, b = a; n / j >= b; j += a, b++)
        {
            ll req = n / j;
            res += req - b + 1;
        }
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