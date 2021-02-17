#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool cube_root(ll x)
{
    if (x == 0)
        return false;
    ll l = 0, r = 1e6 + 1;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    return (l * l * l == x);
}

bool solve()
{
    ll x;
    cin >> x;
    for (ll i = 1; i * i * i <= x; i++)
        if (cube_root(x - i * i * i))
            return true;
    return false;
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