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

ll I = 1, J = 3, K = 5;
vector<ll> arr = {3, 2, 1, 6, 5, 4};

ll calc(ll l, ll r)
{
    ll cnt = 0;
    l--;
    r--;
    for (ll i = l; i < r; i++)
        for (ll j = i + 1; j <= r; j++)
            if (arr[i] > arr[j])
                cnt++;
    return cnt;
}

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
    // ans = calc(l, r);
    // d(ans);
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    ll low = 1, high = n, res = 1;
    ll mx = query(1, n);
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll q = query(1, mid);
        if (q == 0)
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
        {
            ll v = check_sqrt(2 * q);
            if (nc2(v) == q)
            {
                res = max(res, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }
    ll q = query(1, res);
    ll v1 = check_sqrt(2 * q), v2 = check_sqrt(2 * (mx - q));
    ll j = res, k = res + v2 - 1, i = res - v1;
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