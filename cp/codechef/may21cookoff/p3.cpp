#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll x, y, res = 0, b = 0;
    cin >> x >> y;
    if (y % x > 0)
        return -1;
    y /= x;
    for (ll i = 60; i > 0; i--)
    {
        ll v = (1ll << i) - 1;
        if (v <= y)
        {
            res += i + 1;
            y -= v;
        }
    }
    return (y == 0) ? res - 1 : -1;
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