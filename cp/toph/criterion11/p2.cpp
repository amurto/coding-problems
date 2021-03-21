#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 1e5 + 5;

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

// factorial and inverse factorial
int fact[N], invfact[N];
void init()
{
    fact[0] = fact[1] = 1;
    int i;
    for (i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
    i--;
    // Fermat's Little Theorem
    // 1/(a! % mod) = a^mod-2 % mod
    invfact[i] = power(fact[i], MOD - 2, MOD);
    for (i--; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * 1ll * (i + 1)) % MOD;
}

int f(int a, int b)
{
    return mul(fact[a + b - 2], mul(invfact[a - 1], invfact[b - 1]));
}

int g(int a, int b, int r, int c)
{
    return mul(r - a + 1, c - b + 1);
}

bool cmp(int r, int c, int r1, int c1, int r2, int c2)
{
    if (max(r1, c1) == max(r2, c2))
        return (r - r1 + 1) * 1ll * (c - c1 + 1) > (r - r2 + 1) * 1ll * (c - c2 + 1);
    return max(r1, c1) < max(r2, c2);
}

int solve()
{
    int r, c, l, res = 0, c1 = 0, c2;
    cin >> r >> c >> l;
    int req = l + 1;
    if (req > r + c)
        return 0;
    int beg = 1, end = min(r, c);
    while (beg < end)
    {
        int m1 = beg + (end - beg) / 3;
        int m2 = end - (end - beg) / 3;
        if (cmp(r, c, m1, req - m1, m2, req - m2))
            end = m2 - 1;
        else
            beg = m1 + 1;
    }
    return mul(f(beg, req-beg), g(beg, req-beg, r, c));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}