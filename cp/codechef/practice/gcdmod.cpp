// https://www.codechef.com/problems/GCDMOD
// Modular GCD

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MOD = 1e9 + 7;

// Binary Exponentiation O(logn)
// n^m mod p
// p is large prime number
ll power(ll n, ll m, ll p)
{
    ll res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = ((res % p) * (n % p)) % p;
        n = ((n % p) * (n % p)) % p;
        m /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        ll R = a - b, d = 1;
        if (a == b)
        {
            cout << (power(a, n, MOD) + power(b, n, MOD)) % MOD << "\n";
            continue;
        }
        for (ll i = 1; i * i <= R; i++)
        {
            if (R % i == 0)
            {
                ll d1 = i, d2 = R / i;
                if ((power(a, n, d1) + power(b, n, d1)) % d1 == 0)
                    d = max(d, d1);
                if ((power(a, n, d2) + power(b, n, d2)) % d2 == 0)
                    d = max(d, d2);
            }
        }
        cout << d << "\n";
    }
    return 0;
}