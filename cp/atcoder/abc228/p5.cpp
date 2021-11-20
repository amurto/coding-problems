#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353;

int add(int x, int y, int m = MOD)
{
    x += y;
    while (x >= m)
        x -= m;
    while (x < 0)
        x += m;
    return x;
}

int mul(ll x, ll y, int m = MOD)
{
    x %= m;
    y %= m;
    return (x * 1ll * y) % m;
}

// Binary Exponentiation O(logn)
// n^m mod p
int power(ll n, ll m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = mul(res, n, p);
        n = mul(n, n, p);
        m /= 2;
    }
    return res;
}

int solve()
{
    ll n, k, m;
    cin >> n >> k >> m;
    if (m % MOD == 0)
        return 0;
    return power(m, power(k, n, MOD - 1), MOD);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}