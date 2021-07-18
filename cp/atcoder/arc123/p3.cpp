#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool calc(ll n, ll x)
{
    while (n > 0 && x > 0)
    {
        ll mn = x, mx = 3 * x;
        if (n <= mx)
            n = 0;
        else
        {
            int d = n % 10;
            while (mx > 0 && (mx % 10) != d)
                mx--;
            if (mx == 0)
                return false;
            if (mx < mn)
                x = mx;
            n -= mx;
            n /= 10;
        }
    }
    return true;
}

ll solve()
{
    ll n, mn = 0;
    cin >> n;
    for (ll i = 1; mn == 0 && i <= 1000; i++)
        if (calc(n, i))
            mn = i;
    return mn;
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