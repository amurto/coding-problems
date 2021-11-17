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

const int MOD = 998244353, N = 1e6 + 5;

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

// O(n)
int cnt[N + 1];
map<ll, int> mp;
vector<int> lp(N + 1), pr;
void linear_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

// Segmented Sieve
// Returns biggest prime for each number from l to r
// r-l+1 should not be too big
vector<ll> segmented_sieve(ll l, ll r)
{
    int sz = r - l + 1;
    vector<ll> big_pr(sz);
    for (int i = 0; i < sz; i++)
        big_pr[i] = l + i;
    for (int x : pr)
    {
        for (ll i = x * 1ll * ((l + x - 1) / x); i <= r; i += x)
        {
            while (big_pr[i - l] % x == 0)
            {
                big_pr[i - l] /= x;
                cnt[x]++;
            }
        }
    }
    return big_pr;
}

int solve()
{
    int res = 1;
    ll n, k;
    cin >> n >> k;
    if (k > n - k)
        k = n - k;
    for (int i = 1; i <= N; i++)
        cnt[i] = 0;
    vector<ll> big_pr = segmented_sieve(n - k + 1, n);
    for (ll x : big_pr)
        if (x > 1)
            mp[x]++;
    for (ll i = 2; i <= k; i++)
    {
        ll j = i;
        while (j > 1)
        {
            cnt[lp[j]]--;
            j /= lp[j];
        }
    }
    for (int x : pr)
        res = mul(res, cnt[x] + 1);
    for (auto x : mp)
        res = mul(res, x.second + 1);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    cout << solve() << "\n";
    return 0;
}