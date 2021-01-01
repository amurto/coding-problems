// https://www.hackerrank.com/contests/infinitum18/challenges/tower-3-coloring
// Tower 3-coloring

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

// We have to find 3^k where k = 3^n
// a^m-1 mod m = 1 where m is prime (Fermat's little Theorem) .... (1)
// k can be represented as q * (m - 1) + r
// ans = 3^(q * (m - 1) + r) mod m
// 3^(m-1 * q) mod m * 3^r mod m
// By (1), 3^(m-1) mod m = 1 
// Substituting, ans = 1^q * 3^r mod m
// ans = 3^r mod m where r = 3^n mod m-1
// Now fast exponentiation is possible
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << power(3, power(3, n, MOD - 1), MOD) << "\n";
    return 0;
}