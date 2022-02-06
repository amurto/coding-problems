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
ll ten[19];
int add(int x, int y)
{
    x += y;
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

int nc2(ll x)
{
    x %= MOD;
    return mul(x, x + 1);
}

int cnt_digits(ll n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int solve()
{
    ll n;
    cin >> n;
    int res = 0, cnt = cnt_digits(n);
    for (int t = 1; t <= cnt; t++)
    {
        ll nums = 0;
        if (t == cnt)
            nums = n - ten[t - 1] + 1;
        else
            nums = ten[t - 1] * 9;
        res = add(res, nc2(nums));
    }
    int inv2 = power(2, MOD - 2, MOD);
    res = mul(res, inv2);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ten[0] = 1;
    for (int i = 1; i < 19; i++)
        ten[i] = 1ll * ten[i - 1] * 10;
    cout << solve() << "\n";
    return 0;
}