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

const int MOD = 998244353, K = 26, N = 23, MX = 2e4 + 5;

int arr[N][K], st[1 << N][K], dp[1 << N];
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

ll solve()
{
    int n;
    cin >> n;
    ll res = 0;
    for (int j = 0; j < K; j++)
        st[0][j] = MX;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (char ch : str)
            arr[i][ch - 'a']++;
    }
    dp[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        int cnt = __builtin_popcount(mask);
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
            {
                int low_mask = mask ^ (1 << i);
                for (int j = 0; j < K; j++)
                    st[mask][j] = min(arr[i][j], st[low_mask][j]);
                break;
            }
        }
        dp[mask] = 1;
        for (int j = 0; j < K; j++)
            dp[mask] = mul(dp[mask], st[mask][j] + 1);
        if (!(cnt & 1))
            dp[mask] = -dp[mask];
    }
    for (int i = 0; i < n; i++)
        for (int mask = 0; mask < (1 << n); mask++)
            if ((mask >> i) & 1)
                dp[mask] = add(dp[mask], dp[mask ^ (1 << i)]);
    for (int mask = 0; mask < (1 << n); mask++)
    {
        ll v = 0;
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1)
                v += (i + 1);
        v *= __builtin_popcount(mask);
        v *= dp[mask];
        res ^= v;
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