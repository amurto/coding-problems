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

ll nc2(ll x)
{
    return (x * (x - 1)) / 2;
}

ll check_sqrt(ll x)
{
    ll l = 2, r = 2e9 + 1;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * (mid - 1) > x)
            r = mid - 1;
        else
            l = mid;
    }
    return l;
}

ll query(ll l, ll r)
{
    cout << "? " << l << " " << r << endl;
    ll ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    ll low = 1, high = n;
    ll mx = query(1, n);
    while (low < high)
    {
        ll mid = low + (high - low) / 2;
        ll q = query(1, mid);
        if (q >= mx)
            high = mid;
        else
            low = mid + 1;
    }
    ll sz2 = mx - query(1, low - 1) + 1;
    ll sz1 = check_sqrt(2 * (mx - nc2(sz2)));
    ll j = low - sz2 + 1, k = low, i = low - sz1 - sz2 + 1;
    cout << "! " << i << " " << j << " " << k << endl;
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