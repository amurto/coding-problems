#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MOD = 1000000007, N = 3e5 + 1;

ll add(ll x, ll y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

ll sub(ll x, ll y)
{
    if (x - y < 0)
        return x - y + MOD;
    return x - y;
}

ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

// Binary Exponentiation O(logn)
// n^m mod p
// p is large prime number
ll power(ll n, ll m, ll p)
{
    ll res = 1;
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
ll fact[N], invfact[N];
void init()
{
    fact[0] = fact[1] = 1;
    ll i;
    for (i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
    i--;
    // Fermat's Little Theorem
    // 1/(a! % mod) = a^mod-2 % mod
    invfact[i] = power(fact[i], MOD - 2, MOD);
    for (i--; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * 1ll * (i + 1)) % MOD;
}

// NCR
// n!/r!*(n-r)!
ll ncr(ll n, ll r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return mul(fact[n], mul(invfact[r], invfact[n - r]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll two[n + 1];
    two[0] = 1;
    for (ll i = 1; i <= n; i++)
        two[i] = mul(two[i - 1], 2);
    vector<pair<ll, ll>> iv(n);
    for (int i = 0; i < n; i++)
        cin >> iv[i].first >> iv[i].second;
    sort(iv.begin(), iv.end());
    ll cnt = 0, res = 0;
    vector<bool> rem(n);
    for (int i = 1; i < n - 1; i++)
    {
        if (iv[i - 1].second >= iv[i + 1].first)
        {
            rem[i] = true;
            cnt++;
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        ll temp = cnt;
        if (rem[i - 1])
            temp--;
        if (rem[i + 1])
            temp--;
    }
    cout << two[cnt] << "\n";
    return 0;
}