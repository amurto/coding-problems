#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll sq_root(ll x)
{
    ll l = 0, r = 2e9 + 1;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    return l;
}

ll solve()
{
    ll n;
    cin >> n;
    return n - sq_root(n);
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