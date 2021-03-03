// https://codeforces.com/contest/1295/problem/D
// Same GCDs

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

ll solve()
{
    ll a, m;
    cin >> a >> m;
    ll g = __gcd(a, m);
    return phi(m / g);
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