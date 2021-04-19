// https://codeforces.com/contest/1155/problem/D
// Beautiful Array

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> arr(n + 2), tmp(n + 2), suf(n + 2), dp(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        tmp[i] = arr[i] * x;
    }
    for (int i = n; i > 0; i--)
        suf[i] = max(suf[i + 1] + arr[i], max(0ll, arr[i]));
    for (int i = n; i > 0; i--)
        dp[i] = max(0ll, max(suf[i], max(tmp[i], tmp[i] + dp[i + 1])));
    ll res = dp[1], sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = max(sum + arr[i], max(0ll, arr[i]));
        res = max(res, sum + dp[i + 1]);
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