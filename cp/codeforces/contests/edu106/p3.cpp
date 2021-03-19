#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n), pmn(n), dp(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    pmn[0] = arr[0];
    pmn[1] = arr[1];
    for (int i = 2; i < n; i++)
        pmn[i] = min(pmn[i - 2], arr[i]);
    ll res = arr[0] * n + arr[1] * n;
    dp[1] = res;
    vector<ll> par(2, 1);
    for (int i = 2; i < n; i++)
    {
        ll prev = dp[i - 1];
        if (pmn[i - 2] > arr[i])
        {
            ll idx = par[i % 2];
            prev -= (n - (idx - 1)) * pmn[i - 2];
            prev += pmn[i - 2];
            prev += (n - idx) * arr[i];
        }
        else
        {
            prev -= pmn[i];
            prev += arr[i];
        }
        dp[i] = prev;
        res = min(res, dp[i]);
        par[i % 2]++;
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