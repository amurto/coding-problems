#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353;

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    if (n == 0)
        return 0;
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

int solve()
{
    int n, m, k, res = 0;
    cin >> n >> m >> k;
    if (n + m == 2)
        return k;
    if (n == 1)
        return power(k, m, MOD);
    if (m == 1)
        return power(k, n, MOD);
    for (int i = 1; i <= k; i++)
        res = add(res, mul(add(power(i, n, MOD), -power(i - 1, n, MOD)), power(k - i + 1, m, MOD)));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}