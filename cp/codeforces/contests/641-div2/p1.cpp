#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll f(ll x)
{
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
            return i;
    return x;
}

ll solve()
{
    ll n, k;
    cin >> n >> k;
    n += f(n) + (k - 1) * 2;
    return n;
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