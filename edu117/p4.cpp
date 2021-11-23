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

bool calc(ll a, ll b, ll x)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a == x;
    bool pos = false;
    if (a == x || b == x)
        pos = true;
    if (x < a)
    {
        if ((x - a) % b == 0)
            pos = true;
    }
    if (calc(a % b, b, x))
        pos = true;
    return pos;
}

bool solve()
{
    ll a, b, x;
    cin >> a >> b >> x;
    return calc(a, b, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}