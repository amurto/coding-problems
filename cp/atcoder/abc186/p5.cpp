#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll solve()
{
    ll n, s, k;
    cin >> n >> s >> k;
    ll g = __gcd(n, k);
    s = n - s;
    if (s % g)
        return -1;
    n /= g;
    k /= g;
    s /= g;
    ll x, y;
    gcd(k, n, x, y);
    x = x * s % n;
    while (x < 0)
        x += n;
    return x;
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