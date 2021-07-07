// https://codeforces.com/contest/1097/problem/D
// Makoto and a Blackboard

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 2e4 + 5;

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

map<ll, int> primes, divs;
vector<ll> st;

void dfs(int cur, ll d, int v, ll n, int k)
{
    if (cur == st.size())
    {
        divs[n / d] = v;
        cout << n / d << " " << v << "\n";
        return;
    }
    ll tmp = d;
    int mx = primes[st[cur]];
    for (int i = 0; i <= mx; i++, tmp *= st[cur])
        dfs(cur + 1, tmp, mul(v, ncr(i + k, i)), n, k);
}

int solve()
{
    ll n;
    int k;
    cin >> n >> k;
    ll x = n;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            st.pb(i);
            ll cnt = 0;
            while (x % i == 0)
            {
                x /= i;
                cnt++;
            }
            primes[i] = cnt;
        }
    }
    if (x > 1)
    {
        st.pb(x);
        primes[x] = 1;
    }
    // for (int i = 0; i < st.size(); i++)
    //     cout << st[i] << " -> " << primes[st[i]] << "\n";
    dfs(0, 1, 1, n, k);
    int num = 0, den = 0;
    for (auto d : divs)
    {
        int cur = d.first % MOD;
        num = add(num, mul(cur, d.second));
        den = add(den, d.second);
    }
    return mul(num, power(den, MOD - 2, MOD));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << solve() << "\n";
    return 0;
}