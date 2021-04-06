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
double flog[N];
void init()
{
    fact[0] = fact[1] = 1;
    flog[0] = 0;
    flog[1] = logl(1);
    int i;
    for (i = 2; i < N; i++)
    {
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
        flog[i] = flog[i - 1] + logl(i);
    }
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

long double calc(int a, int b, int r, int c, int l)
{
    return log(r - a + 1) + log(c - b + 1) + flog[l - 1] - flog[a - 1] - flog[b - 1];
}

int solve()
{
    int r, c, l, res = 0, c1 = 0, c2;
    cin >> r >> c >> l;
    int req = l + 1;
    if (r + c - 1 < l)
        return 0;
    int beg = 1, end = min(l, r);
    while (beg < end)
    {
        int m1 = beg + (end - beg) / 3;
        int m2 = end - (end - beg) / 3;
        if (calc(m1, l + 1 - m1, r, c, l) > calc(m2, l + 1 - m2, r, c, l))
            end = m2 - 1;
        else
            beg = m1 + 1;
    }
    return mul(f(beg, l + 1 - beg), g(beg, l + 1 - beg, r, c));
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