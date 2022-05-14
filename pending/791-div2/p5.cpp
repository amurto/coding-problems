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

const int MOD = 998244353, K = 17;

int add(int x, int y)
{
    x += y;
    x %= MOD;
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
int power(int n, ll m, int p)
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

void solve()
{
    int n, q;
    string str;
    cin >> n >> str >> q;
    vector<ll> dp(1 << K);
    vector<int> pal(1 << K);
    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        ll num = 0;
        for (int l = i, r = i; l >= 0 && r < n; l--, r++)
        {
            if (str[l] != '?' && str[r] != '?' && str[l] != str[r])
                break;
            if (str[l] == '?' && str[r] == '?')
                num++;
            else if (str[l] == '?' && str[r] != '?')
                mask |= (1 << (str[r] - 'a'));
            else if (str[l] != '?' && str[r] == '?')
                mask |= (1 << (str[l] - 'a'));
            if (num == 0)
                pal[mask] = add(pal[mask], 1);
            dp[mask] += num;
        }
        mask = 0;
        num = 0;
        for (int l = i, r = i + 1; l >= 0 && r < n; l--, r++)
        {
            if (str[l] != '?' && str[r] != '?' && str[l] != str[r])
                break;
            if (str[l] == '?' && str[r] == '?')
                num++;
            else if (str[l] == '?' && str[r] != '?')
                mask |= (1 << (str[r] - 'a'));
            else if (str[l] != '?' && str[r] == '?')
                mask |= (1 << (str[l] - 'a'));
            if (num == 0)
                pal[mask] = add(pal[mask], 1);
            dp[mask] += num;
        }
    }
    for (int i = 0; i < K; ++i)
        for (int mask = 0; mask < (1 << K); ++mask)
            if (mask & (1 << i))
                dp[mask] += dp[mask ^ (1 << i)];
    for (int i = 0; i < q; i++)
    {
        string t;
        cin >> t;
        int mask = 0, sz = (int)t.length();
        for (char ch : t)
            mask |= (1 << (ch - 'a'));
        int ans = power(sz, dp[mask], MOD);
        ans = add(ans, pal[mask]);
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}