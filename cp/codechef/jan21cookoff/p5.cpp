#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int count_pow(int n)
{
    for (int i = 0; i <= 20; i++)
        if ((1 << i) >= n)
            return i;
    return 20;
}

ll solve()
{
    int n;
    cin >> n;
    int k = count_pow(n);
    vector<int> arr(n);
    vector<ll> f(1 << k), dp(1 << k);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        f[arr[i]]++;
    }
    for (int b = 0; b < k; b++)
        for (int mask = (1 << k) - 1; mask >= 0; mask--)
            if (!((mask >> b) & 1))
                f[mask] += f[mask ^ (1 << b)];
    dp[(1 << k) - 1] = f[(1 << k) - 1] * ((1 << k) - 1);
    for (int mask = (1 << k) - 1; mask >= 0; mask--)
        for (int b = 0; b < k; b++)
            if ((mask >> b) & 1)
                dp[mask ^ (1 << b)] = max(dp[mask ^ (1 << b)], dp[mask] + (f[mask ^ (1 << b)] - f[mask]) * (mask ^ (1 << b)));
    return dp[0];
}

signed main()
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