// https://codeforces.com/contest/919/problem/E
// Congruence Equation

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int mul(int x, int y, int MOD)
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

ll solve()
{
    int a, b, p;
    ll x, res = 0;
    cin >> a >> b >> p >> x;
    ll den = p * 1ll * (p - 1);
    vector<int> seq(p);
    seq[0] = 1;
    for (int i = 1; i < p; i++)
        seq[i] = mul(seq[i - 1], a, p);
    for (int i = 1; i < p; i++)
    {
        int c = mul(b, power(seq[i], p - 2, p), p);
        ll cur = i + 1ll * ((i - c + p) % p) * (p - 1);
        if (cur <= x)
            res += (x - cur) / (den) + 1;
    }
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