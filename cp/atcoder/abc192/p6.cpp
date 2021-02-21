#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll ninf = -1e9 - 5;

ll solve()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll res = 1e18;
    for (int c = n; c >= 1; c--)
    {
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, ninf)));
        for (int i = c; i <= n; i++)
            dp[i][c][x % c] = 0;
        for (int j = c - 1; j >= 0; j--)
            for (int i = n-1; i >= 0; i--)
                for (int k = 0; k < c; k++)
                    dp[i][j][k] = max(dp[i + 1][j][k], arr[i] + dp[i + 1][j + 1][(k + arr[i]) % c]);
        if (dp[0][0][0] > 0)
            res = min(res, (x - dp[0][0][0]) / c);
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