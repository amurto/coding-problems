// https://codeforces.com/contest/1334/problem/E
// Divisor Paths

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

const int MOD = 998244353, N = 100;

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

vector<ll> factorise(ll x)
{
    vector<ll> pr;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            pr.pb(i);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        pr.pb(x);
    return pr;
}

int dis(vector<ll> &pr, ll u, ll v)
{
    if (u == v)
        return 1;
    int res = 1, sum = 0;
    ll req = v / u;
    for (ll p : pr)
    {
        if (req % p == 0)
        {
            int cnt = 0;
            while (req % p == 0)
            {
                req /= p;
                cnt++;
            }
            res = mul(res, invfact[cnt]);
            sum += cnt;
        }
    }
    res = mul(res, fact[sum]);
    return res;
}

void solve()
{
    ll D, u, v;
    int q;
    cin >> D >> q;
    vector<ll> pr = factorise(D);
    for (int i = 0; i < q; i++)
    {
        cin >> u >> v;
        if (u == v)
            cout << 1 << "\n";
        else
        {
            ll g = __gcd(u, v);
            int res = mul(dis(pr, g, u), dis(pr, g, v));
            cout << res << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}