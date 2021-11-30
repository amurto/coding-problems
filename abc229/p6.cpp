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

const ll inf = 1e18;
ll solve()
{
    int n;
    cin >> n;
    ll res = inf;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    // have not deleted (root-0)
    vector<ll> dp(n, inf);
    dp[0] = a[0];
    dp[1] = b[0];
    for (int i = 2; i < n - 1; i++)
        dp[i] = min(dp[i], min(dp[i - 2] + a[i - 1], dp[i - 1] + b[i - 1]));
    res = min(dp[n - 1] + b[n - 1], dp[n - 2] + a[n - 1]);
    // have deleted (root-0)
    for (int i = 0; i < n; i++)
        dp[i] = inf;
    dp[1] = a[0];
    for (int i = 2; i < n; i++)
        dp[i] = min(dp[i], min(dp[i - 2] + a[i - 1], dp[i - 1] + b[i - 1]));
    res = min(res, dp[n - 1]);
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