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
    ll n2, n3, n4, res = 0;
    cin >> n2 >> n3 >> n4;
    ll s334 = min(n3 / 2, n4);
    res += s334;
    n4 -= s334;
    n3 -= s334 * 2;
    ll s2233 = min(n2 / 2, n3 / 2);
    res += s2233;
    n3 -= s2233 * 2;
    n2 -= s2233 * 2;
    ll low = 0, high = n2, req = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll r2 = n2 - mid;
        ll r4 = n4 + r2 / 2;
        if (mid * 2 <= r4)
        {
            req = max(req, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    res += req;
    return res;
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