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

int solve()
{
    int x, y;
    cin >> x >> y;
    int g = __gcd(x, y);
    if (g > 1)
        return 0;
    if (__gcd(x + 1, y) > 1 || __gcd(x, y + 1) > 1)
        return 1;
    return 2;
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