// https://codeforces.com/contest/227/problem/C
// Flying Saucer Segments

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

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
    ll n, m;
    cin >> n >> m;
    ll ans = power(3, n, m) - 1;
    if (ans < 0)
        ans += m;
    cout << ans << "\n";
    return 0;
}