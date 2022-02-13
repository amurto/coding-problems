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

const int MX = 1e4 + 5;
const ll inf = 1e14 + 5;
ll solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n), pre(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    pre[0] = a[0] + b[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i] + b[i];
    vector<ll> dp(MX, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        vector<ll> tdp(MX, inf);
        for (int j = 0; j < MX; j++)
        {
            if (dp[j] < inf)
            {
                ll sum1 = j, sum2 = 0;
                if (i - 1 >= 0)
                    sum2 = pre[i - 1] - j;
                // a[i], b[i]
                if (sum1 + a[i] < MX)
                    tdp[j + a[i]] = min(tdp[j + a[i]], dp[j] + sum1 * a[i] * 2 + sum2 * b[i] * 2);
                // b[i], a[i]
                if (sum1 + b[i] < MX)
                    tdp[j + b[i]] = min(tdp[j + b[i]], dp[j] + sum1 * b[i] * 2 + sum2 * a[i] * 2);
            }
        }
        swap(dp, tdp);
    }
    ll res = inf;
    for (int i = 0; i < MX; i++)
        res = min(res, dp[i]);
    for (int i = 0; i < n; i++)
    {
        res += 1ll * (a[i] * a[i] * (n - 1));
        res += 1ll * (b[i] * b[i] * (n - 1));
    }
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