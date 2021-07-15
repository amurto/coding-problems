#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 2e5 + 5;

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
    // 1/(a! % mod) = a!^mod-2 % mod
    invfact[i] = power(fact[i], MOD - 2, MOD);
    for (i--; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * 1ll * (i + 1)) % MOD;
}

// NCR
// n!/r!*(n-r)!
int ncr(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return mul(fact[n], mul(invfact[r], invfact[n - r]));
}

int solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> arr(n), down(n), up(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = -(i + 1);
        up[i] = arr[i] + r;
        down[i] = arr[i] + l;
    }
    vector<int> tmpD = down, tmpU = up;
    reverse(tmpD.begin(), tmpD.end());
    reverse(tmpU.begin(), tmpU.end());
    int res = 0, mn = min(abs(down[0]), abs(up[n - 1]));
    res = add(res, mul(mn, ncr(n, n / 2)));
    if (n & 1)
        res = add(res, mul(mn, ncr(n, n - n / 2)));
    int mx = min(abs(up[0]), abs(down[n - 1]));
    for (int i = mn + 1; i <= mx; i++)
    {
        int pos = lower_bound(tmpU.begin(), tmpU.end(), i) - tmpU.begin();
        pos = n - pos;
        int neg = upper_bound(tmpD.begin(), tmpD.end(), -i) - tmpD.begin();
        if (pos + neg < n)
            continue;
        int bth = max(0, neg - (n - pos));
        pos -= bth;
        neg -= bth;
        res = add(res, ncr(bth, n / 2 - pos));
        if (n & 1)
            res = add(res, ncr(bth, (n - n / 2) - pos));
    }
    return res;
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