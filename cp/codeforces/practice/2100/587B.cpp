// https://codeforces.com/contest/587/problem/B
// Duff in Beach

#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

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

int solve()
{
    ll n, l, k, res = 0;
    cin >> n >> l >> k;
    ll dv = l / n;
    ll rem = l % n;
    rem--;
    ll mx = min(n * k, l);
    vector<int> arr(n), dp(n * k), ids(n), seq(n), pre(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        seq[i] = arr[i];
    }
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return arr[i1] < arr[i2]; });
    sort(seq.begin(), seq.end());
    for (int i = 0; i < min(n, l); i++)
        dp[i] = 1;
    for (int i = n; i < mx; i += n)
    {
        for (int j = 1; j < n; j++)
            pre[j] = add(pre[j - 1], pre[j]);
        for (int j = i; j < min(mx, i + n); j++)
        {
            int id = upper_bound(seq.begin(), seq.end(), arr[j % n]) - seq.begin();
            dp[j] = pre[id - 1];
        }
        for (int j = 0; j < n; j++)
            if (i + ids[j] < mx)
                pre[j] = dp[i + ids[j]];
    }
    for (int i = 0; i < mx; i++)
    {
        ll x = (i + n) / n;
        ll slots = dv + ((i % n) <= rem);
        slots -= x;
        slots++;
        res = add(res, mul(slots%MOD, dp[i]));
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