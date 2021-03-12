// Sum of Subset DP

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Check if a certain subset sum is possible
// O(n^2)
bool possible(vector<int> &arr, int n, int sum)
{
    vector<vector<int>> dp(n + 1, vector<int>(1005));
    for (int i = 0; i <= n; i++)
        dp[i][sum] = 1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < n; j++)
            dp[i][j] = dp[i + 1][j] || dp[i + 1][j + arr[i]];
    return dp[0][0];
}

// O(n*sqrt(n))
// If sum of array is n, then number of distinct values in array is bounded by sqrt(n)
bool possibleSqrt(vector<int> &arr, int n, int sum)
{
    sort(arr.begin(), arr.end());
    vector<bool> vis(sum + 1);
    vis[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int r = i;
        while (r < n && arr[r] == arr[i])
            r++;
        vector<int> cnt(n + 1);
        for (int cur = arr[i]; cur <= sum; cur++)
        {
            if (!vis[cur] && vis[cur - arr[i]] && cnt[cur - arr[i]] < r - i)
            {
                cnt[cur] = cnt[cur - arr[i]] + 1;
                vis[cur] = true;
            }
        }
        i = r - 1;
    }
    return vis[sum];
}