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

int add(int x, int y)
{
    x += y;
    x %= MOD;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

// Binary Exponentiation O(logn)
// n^m mod p
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

int solve()
{
    int n;
    cin >> n;
    if (n == 1)
        return 1;
    int res = mul(3, add(power(2, n, MOD), -1));
    res = add(res, -add(power(2, n - 1, MOD), -1));
    int pal = 0;
    if (n & 1)
        pal = add(-2, add(power(2, (n + 1) / 2, MOD), power(2, n / 2, MOD)));
    else
        pal = add(-2, add(power(2, n / 2, MOD), power(2, n / 2, MOD)));
    res = add(res, -mul(2, pal));
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
        cout << solve() << "\n";
    return 0;
}