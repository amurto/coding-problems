#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 3e3 + 5;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1)), last(n + 1, vector<int>(n + 1));
    for (int k = 1; k <= n; k++)
    {
        vector<int> div(k + 1, -1);
        div[0] = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += arr[i] % k;
            sum %= k;
            last[i][k] = div[sum];
            div[sum] = i;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= i; k++)
        {
            int l = last[i][k];
            if (l >= 0)
                dp[i][k] = add(dp[l][k], dp[l][k - 1]);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = add(res, dp[n][i]);
    cout << res << "\n";
    return 0;
}