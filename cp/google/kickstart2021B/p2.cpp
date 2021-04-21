#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e18 + 7;
int solve()
{
    int n, res = 2;
    cin >> n;
    vector<ll> arr(n), pre(n, inf), suf(n, inf);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 2)
        return 2;
    for (int i = 1; i < n; i++)
        pre[i] = arr[i] - arr[i - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = arr[i + 1] - arr[i];
    vector<vector<int>> dp(2, vector<int>(n));
    for (int j = 0; j < 2; j++)
    {
        ll d = arr[1] - arr[0];
        dp[j][0] = 1;
        dp[j][1] = 2;
        for (int i = 2; i < n; i++)
        {
            if (arr[i] - arr[i - 1] == d)
                dp[j][i] += 1 + dp[j][i - 1];
            else
            {
                d = arr[i] - arr[i - 1];
                dp[j][i] = 2;
            }
        }
        reverse(arr.begin(), arr.end());
    }
    reverse(dp[1].begin(), dp[1].end());
    // cout << "\n";
    // for (int i = 0; i < n; i++)
    //     cout << dp[0][i] << " ";
    // cout << "\n";
    // for (int i = 0; i < n; i++)
    //     cout << dp[1][i] << " ";
    // cout << "\n";
    // for (int i = 0; i < n; i++)
    //     cout << pre[i] << " ";
    // cout << "\n";
    // for (int i = 0; i < n; i++)
    //     cout << suf[i] << " ";
    // cout << "\n";
    for (int i = 0; i < n; i++)
    {
        res = max(res, max(dp[0][i], dp[1][i]));
        if (i < n - 1)
            res = max(res, 1 + dp[1][i + 1]);
        if (i > 0)
            res = max(res, 1 + dp[0][i - 1]);
        if (i > 0 && i < n - 1)
        {
            if (pre[i - 1] == inf && suf[i + 1] == inf)
            {
                if ((arr[i + 1] - arr[i - 1]) % 2 == 0)
                    res = max(res, 3);
            }
            else
            {
                ll d1 = pre[i - 1], d2 = suf[i + 1], diff = arr[i + 1] - arr[i - 1];
                ll p = diff % 2, h = diff / 2;
                if (p == 0)
                    res = max(res, 3);
                if (d1 != inf && p == 0 && h == d1)
                    res = max(res, dp[0][i - 1] + 2);
                if (d2 != inf && p == 0 && h == d1)
                    res = max(res, dp[1][i + 1] + 2);
                if (d1 == d2 && p == 0 && h == d1)
                    res = max(res, dp[0][i - 1] + 1 + dp[1][i + 1]);
            }
        }
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
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}