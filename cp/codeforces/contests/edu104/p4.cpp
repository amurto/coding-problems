#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll sqroot(ll x)
{
    if (x == 0 || x == 1)
        return x;
    ll start = 1, end = x, ans;
    while (start <= end)
    {
        ll mid = (start + end) / 2;
        if (mid * mid == x)
            return mid;
        if (mid * mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    return ans;
}

ll solve()
{
    ll n, res = 0;
    cin >> n;
    ll ub = sqroot(n + n - 1);
    if (ub % 2 == 0)
        ub--;
    return ub / 2;
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