// https://codeforces.com/contest/707/problem/C
// Pythagorean Triples

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool ps(ll v)
{
    ll s = floor(sqrt(v));
    return (s * s == v);
}

bool fac(ll n, ll v1)
{
    ll v2 = n / v1;
    if (v1 < v2)
        swap(v1, v2);
    ll p1 = v2 + (v1 - v2) / 2;
    ll p2 = v1 - p1;
    if (p1 > 0 && p2 > 0 && max(p1, p2) - min(p1, p2) == v2)
    {
        cout << min(p1, p2) << " " << max(p1, p2) << "\n";
        return true;
    }
    return false;
}

void solve()
{
    ll n;
    cin >> n;
    n*=n;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0 && fac(n, i))
            return;
    }
    cout << "-1\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
