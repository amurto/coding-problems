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
    ll a, b, c;
    cin >> a >> b >> c;
    ll sum = a + b * 2 + c * 3;
    if (sum & 1)
        return 1;
    sum /= 2;
    sum -= (3 * min(sum / 3, c));
    sum -= (2 * min(sum / 2, b));
    sum -= min(sum, a);
    return (sum == 0) ? 0 : 1;
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