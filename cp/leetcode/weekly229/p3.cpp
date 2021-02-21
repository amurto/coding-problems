#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int maximumScore(vector<int> &nums, vector<int> &multipliers)
{
    int n = nums.size(), m = multipliers.size();
    vector<vector<int>> dp(m + 1, vector<int>(m + 1));
    for (int i = 0; i <= m; i++)
        dp[m][i] = 0;
    for (int i = m - 1; i >= 0; i--)
        for (int j = i; j >= 0; j--)
            dp[i][j] = max(multipliers[i] * nums[i - j] + dp[i + 1][j], multipliers[i] * nums[n - j - 1] + dp[i + 1][j + 1]);
    return dp[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> nums = {1, 2, 3}, multipliers = {3, 2, 1};
    cout << maximumScore(nums, multipliers) << "\n";
    return 0;
}