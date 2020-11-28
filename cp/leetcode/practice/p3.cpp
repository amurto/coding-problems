// https://leetcode.com/problems/target-sum/
// Target Sum

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int findTargetSumWays(vector<int> &nums, int S)
{
    int sum = 0, p = 0;
    for (int num : nums)
        sum += num;
    if (sum < S)
        return 0;
    vector<int> dp(1000 + sum + 1, 0);
    dp[1000] = 1;
    for (int num : nums)
    {
        vector<int> temp(1000 + sum + 1, 0);
        for (int j = 1000 - p; j <= 1000 + p; j++)
        {
            temp[j - num] += dp[j];
            temp[j + num] += dp[j];
        }
        p += num;
        dp = temp;
    }
    return dp[1000 + S];
}

int main()
{
    vector<int> nums = {10, 20, 30, 40, 50};
    int S = 60;
    cout << findTargetSumWays(nums, S) << "\n";
    return 0;
}
