#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

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

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    if (n == 1)
        return arr[1];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = add(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0];
    }
    for (int i = 2; i <= n; i++)
    {
        int l = i - 2, r = n - i;
        int pos = 0, neg = 0;
        if (l == 0)
            pos = add(dp[r][0], dp[r][1]);
        else if (r == 0)
            pos = add(dp[l][0], dp[l][1]);
        else
            pos = mul(add(dp[l][0], dp[l][1]), add(dp[r][0], dp[r][1]));
        if (l == 0)
            neg = dp[r][0];
        else if (r == 0)
            neg = dp[l][0];
        else
            neg = mul(dp[l][0], dp[r][0]);
        res = add(res, mul(arr[i], add(pos, -neg)));
    }
    res = add(res, mul(arr[1], add(dp[n - 1][0], dp[n - 1][1])));
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