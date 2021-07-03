#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353;

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

int dfs(vector<vector<int>> &dp, vector<int> &arr, int cur, int mn, int pos, int x)
{
    if (mn < 0)
        return 0;
    if (cur == arr.size())
        return 1;
    if (dp[cur][mn] == -1)
    {
        int res = 0;
        // choose
        if (cur < pos)
        {
            if (arr[cur] == 0)
                res = add(res, dfs(dp, arr, cur + 1, max(0, mn - 1), pos, x));
            else
                res = add(res, dfs(dp, arr, cur + 1, mn + (arr[cur] <= x), pos, x));
        }
        else
        {
            if (arr[cur] == 0)
                res = add(res, dfs(dp, arr, cur + 1, mn - 1, pos, x));
            else
                res = add(res, dfs(dp, arr, cur + 1, mn + (arr[cur] < x), pos, x));
        }
        // not choose
        res = add(res, dfs(dp, arr, cur + 1, mn, pos, x));
        dp[cur][mn] = res;
    }
    return dp[cur][mn];
}

int solve()
{
    int n, res = 0;
    char ch;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        if (ch == '+')
            cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
                if (i != j)
                    tmp.pb(arr[j]);
            vector<vector<int>> dp(n, vector<int>(n, -1));
            res = add(res, mul(dfs(dp, tmp, 0, 0, i, arr[i]), arr[i]));
        }
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