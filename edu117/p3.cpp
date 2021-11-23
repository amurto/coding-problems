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

ll ap(ll a, ll n, ll diff)
{
    return (n * (2 * a + (n - 1) * diff)) / 2;
}

ll solve()
{
    ll k, x;
    cin >> k >> x;
    if (k == 1)
        return 1;
    ll low = 1, high = k, mx1 = 1, mx2 = 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (ap(1, mid, 1) <= x)
        {
            mx1 = max(mx1, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    x -= ap(1, mx1, 1);
    if (mx1 < k)
        return (x == 0) ? mx1 : mx1 + 1;
    if (x == 0)
        return mx1;
    low = 1, high = k - 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (ap(k - 1, mid, -1) <= x)
        {
            mx2 = max(mx2, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    if (mx2 == k - 1)
        return mx1 + mx2;
    x -= ap(k - 1, mx2, -1);
    if (x > 0)
        mx2++;
    return mx1 + mx2;
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