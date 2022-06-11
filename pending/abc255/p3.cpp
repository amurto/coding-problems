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
    ll x, a, diff, n, res = LLONG_MAX;
    cin >> x >> a >> diff >> n;
    ll last = a + (n - 1) * diff;
    if (diff < 0)
    {
        swap(a, last);
        diff = -diff;
    }
    if (diff == 0)
        return abs(a - x);
    // increase
    if (x <= last)
    {
        if (x < a)
            res = min(res, a - x);
        else
            res = min(res, last - diff * ((last - x) / diff) - x);
    }
    // decrease
    if (x >= a)
    {
        if (x > last)
            res = min(res, x - last);
        else
            res = min(res, x - a - diff * ((x - a) / diff));
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