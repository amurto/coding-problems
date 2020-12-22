#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll gf(ll g, ll n)
{
    ll ld = 1;
    for (ll i = 2; i <= n && i * i <= g; i++)
    {
        if (g % i == 0)
        {
            if (i <= n)
                ld = max(ld, i);
            if (g / i <= n)
                ld = max(ld, g / i);
        }
    }
    return ld;
}

int solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> p(m);
    for (int i = 0; i < m; i++)
        cin >> p[i];
    if (n == 1)
        return 0;
    ll g = 0;
    for (int i = 0; i < m; i++)
        g = __gcd(g, p[i]);
    if (g > n)
        g = gf(g, n);
    return n - g;
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