#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll x, y, a, b, res = 0;
    cin >> x >> y >> a >> b;
    if (x > y)
        swap(x, y);
    if (a > b)
        swap(a, b);
    if (x / a <= y / b)
        return x / a;
    ll low = 0, high = x / a, bnd = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll i1 = x - mid * a, i2 = y - mid * b;
        if (i1 > i2)
            high = mid - 1;
        else
        {
            bnd = max(bnd, mid);
            low = mid + 1;
        }
    }
    res += bnd;
    x -= bnd * a;
    y -= bnd * b;
    if (x > y)
        swap(x, y);
    ll sum = a + b;
    // cout << x << " " << y << "\n";
    ll mx1 = (x / sum) * 2;
    if (x % sum >= a)
        mx1++;
    ll mx2 = (y / sum) * 2;
    if (y % sum >= b)
        mx2++;
    return res + min(mx1, mx2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        cout << solve() << "\n";
    }
    return 0;
}