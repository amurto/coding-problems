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

const int MOD = 1e9 + 7;

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

int cnt_digs(int x)
{
    int dig = 0;
    while (x > 0)
    {
        dig++;
        x >>= 1;
    }
    return dig;
}

int solve()
{
    int n, p, res = 0;
    cin >> n >> p;
    vector<int> arr(n), cnt(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<int> dp(p + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= p; i++)
        dp[i] = add(dp[i - 2], dp[i - 1]);
    for (int i = 1; i <= p; i++)
        dp[i] = add(dp[i - 1], dp[i]);
    for (int i = n - 1; i >= 0; i--)
    {
        int x = arr[i], dig = cnt_digs(arr[i]);
        if (p - dig >= 0)
        {
            cnt[i] = add(cnt[i], dp[p - dig]);
            while (x > 0)
            {
                if (x & 1)
                    x >>= 1;
                else if (x % 4 == 0)
                    x /= 4;
                else
                    break;
                int id = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
                if (id < n && arr[id] == x)
                    cnt[id] = add(cnt[id], -cnt[i]);
            }
            res = add(res, cnt[i]);
        }
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