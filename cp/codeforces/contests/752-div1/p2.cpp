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

const ll inf = 2e18;
ll solve()
{
    ll x, y, n = 0;
    cin >> x >> y;
    if (x == y)
        n = x;
    else if (x > y)
        n = ((inf - y) / x) * x + y;
    else if (y % x == 0)
        n = y;
    else if (y <= 2 * x)
        n = x + (y - x) / 2;
    else
        n = y-(y%x)/2;
    return n;
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