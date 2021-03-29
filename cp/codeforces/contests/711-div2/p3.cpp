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

int solve()
{
    int n, k, res = 1;
    cin >> n >> k;
    vector<vector<int>> dp(n + 5, vector<int>(k + 5));
    for (int j = k - 1, d = 0; j > 0; j--, d ^= 1)
    {
        int sum = 0;
        if (j == k - 1)
            sum++;
        if (d == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                dp[i][j] = add(dp[i][j], sum);
                sum = add(sum, dp[i][j + 1]);
                res = add(res, dp[i][j]);
            }
        }
        else
        {
            for (int i = n; i > 0; i--)
            {
                dp[i][j] = add(dp[i][j], sum);
                sum = add(sum, dp[i][j + 1]);
                res = add(res, dp[i][j]);
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
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}