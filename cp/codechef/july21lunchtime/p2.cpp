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

const int MOD = 1e9 + 7, LGN = 57;

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
    int n, res = 0;
    cin >> n;
    vector<ll> arr(n), st(LGN);
    vector<int> pdp(LGN), z;
    vector<vector<int>> dp(n, vector<int>(LGN));
    ll x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        x ^= arr[i];
    }
    for (int i = 1, j = 0; i < LGN; i++, j++, x >>= 1)
        st[i] = st[i - 1] | ((x & 1ll) << j);
    ll cur = 0;
    pdp[0] = 1;
    for (int id = 0; id < n; id++)
    {
        cur ^= arr[id];
        vector<ll> tmp(LGN);
        for (int i = 1, j = 0; i < LGN; i++, j++, cur >>= 1)
            tmp[i] = tmp[i - 1] | ((cur & 1ll) << j);
        for (int i = LGN - 1; i > 0; i--)
        {
            if (tmp[i] == st[i])
            {
                dp[id][i] = pdp[i - 1];
                pdp[i] = add(pdp[i], dp[id][i]);
            }
        }
        cur = tmp[LGN - 1];
        if (id < n - 1 && cur == st[LGN - 1])
            z.pb(dp[id][LGN - 1]);
    }
    for (int i = 1; i < LGN; i++)
        res = add(res, dp[n - 1][i]);
    int sz = z.size();
    for (int i = 0, rem = sz - 1; i < sz; i++, rem--)
        res = add(res, mul(power(2, rem, MOD), z[i]));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}