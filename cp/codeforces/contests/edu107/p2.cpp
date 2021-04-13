#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll len(ll g)
{
    ll cnt = 0;
    while (g > 0)
    {
        cnt++;
        g /= 10;
    }
    return cnt;
}
ll inc(ll g, ll k, ll m)
{
    while (len(g) != k)
        g *= m;
    return g;
}
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll g = 1;
    for (ll i = 1; i < c; i++)
        g *= 10;
    ll x = inc(g, a, 2), y = inc(g, b, 3);
    cout << x << " " << y << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}