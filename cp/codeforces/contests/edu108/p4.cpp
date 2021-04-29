#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), pre(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i] * b[i];
    ll sum = pre[n], res = pre[n];
    for (int i = 1; i <= n; i++)
        dp[i][i] = a[i] * b[i];
    for (int i = 1; i < n; i++)
        dp[i][i + 1] = a[i] * b[i + 1] + a[i + 1] * b[i];
    for (int gap = 3; gap <= n; gap++)
        for (int l = 1, r = gap; r <= n; l++, r++)
            dp[l][r] = a[l] * b[r] + a[r] * b[l] + dp[l + 1][r - 1];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            res = max(res, sum - pre[j] + pre[i - 1] + dp[i][j]);
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