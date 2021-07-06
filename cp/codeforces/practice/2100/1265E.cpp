// https://codeforces.com/contest/1265/problem/E
// Beautiful Mirrors

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353;

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

int solve()
{
    int n;
    cin >> n;
    int d = power(100, MOD - 2, MOD);
    vector<int> arr(n), p(n), q(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        p[i] = mul(arr[i], d);
        q[i] = mul(100 - arr[i], d);
    }
    int cur = 1, res = 0, x = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = mul(cur, p[i]), tmq = mul(cur, q[i]);
        res = add(res, add(tmp, tmq));
        x = add(x, tmq);
        cur = tmp;
    }
    res = mul(res, power(add(1, -x), MOD - 2, MOD));
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