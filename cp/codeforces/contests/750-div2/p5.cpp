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
int solve()
{
    int n, k = 1;
    cin >> n;
    vector<ll> arr(n + 1), pre(n + 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    reverse(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + arr[i];
    for (int i = 1, mx = 0; mx <= n; i++)
    {
        mx += i;
        if (mx <= n)
            k = i;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
    dp[0][0] = inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
            if (i - j >= 0 && pre[i] - pre[i - j] < dp[i - j][j - 1])
                dp[i][j] = max(dp[i][j], pre[i] - pre[i - j]);
        for (int j = 0; j <= k; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
    }
    int res = 0;
    for (int i = 1; i <= k; i++)
        if (dp[n][i] > 0)
            res = i;
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