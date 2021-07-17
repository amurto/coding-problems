// https://codeforces.com/problemset/problem/837/D
// Round Subset

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, k;
    cin >> n >> k;
    ll v;
    vector<int> two(n + 1), five(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v;
        while (v % 2 == 0)
        {
            two[i]++;
            v /= 2;
        }
        while (v % 5 == 0)
        {
            five[i]++;
            v /= 5;
        }
    }
    int sum = 26 * n + 5;
    vector<vector<int>> dp(k + 1, vector<int>(sum, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<vector<int>> tdp = dp;
        for (int j = 1; j <= min(i, k); j++)
            for (int s = sum - 1; s >= five[i]; s--)
                if (dp[j - 1][s - five[i]] != -1)
                    tdp[j][s] = max(tdp[j][s], two[i] + dp[j - 1][s - five[i]]);
        dp = tdp;
    }
    int res = 0;
    for (int s = 0; s < sum; s++)
        res = max(res, min(s, dp[k][s]));
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