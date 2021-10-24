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

ll lcm(ll x, ll y)
{
    return x * y;
}

void solve()
{
    ll x, k;
    cin >> x >> k;
    cout << 2 * x << " " << lcm(x * k - 1, x * k) << "\n";
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