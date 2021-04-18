// https://codeforces.com/contest/1197/problem/D
// Yet Another Subarray Problem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll ninf = -1e18;
ll solve()
{
    int n, m, k;
    ll res = 0;
    cin >> n >> m >> k;
    vector<ll> arr(n), dp(n + 1, ninf);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n - 1; i >= 0; i--)
    {
        ll sum = 0;
        for (int j = i; j < min(n, i + m); j++)
        {
            sum += arr[j];
            dp[i] = max(dp[i], sum - k + max(0ll, dp[j + 1]));
        }
        res = max(res, dp[i]);
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