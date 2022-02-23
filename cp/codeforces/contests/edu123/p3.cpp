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

void solve()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> arr(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = max(0ll, max(dp[i - 1][0] + arr[i], arr[i]));
        for (int j = 1; j <= i; j++)
        {
            ll val1 = max(dp[i - 1][j] + arr[i], arr[i]);
            ll val2 = max(dp[i - 1][j - 1] + x + arr[i], x + arr[i]);
            dp[i][j] = max(0ll, max(val1, val2));
        }
    }
    ll mx = 0;
    for (int j = 0; j <= n; j++)
    {
        for (int i = 0; i <= n; i++)
            mx = max(mx, dp[i][j]);
        cout << mx << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}