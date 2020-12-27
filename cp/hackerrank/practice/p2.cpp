// https://www.hackerrank.com/contests/infinitum18/challenges/tower-3-coloring
// Tower 3-coloring

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
const ll MOD = 1e9 + 7;

ll power(ll n, ll m, ll p)
{
    ll res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res % p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    cout << power(3, power(3, n, MOD), MOD) << "\n";
    return 0;
}