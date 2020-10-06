// https://practice.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1
// Strictly Increasing Array

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int min_operations(vector<int> nums)
{
    int n = nums.size(), MAX = 0;
    vector<int> dp(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (nums[j] > nums[i] && nums[j] - nums[i] >= j - i)
                dp[i] = max(dp[i], 1 + dp[j]);
        }
        MAX = max(MAX, dp[i]);
    }
    return nums.size() - MAX;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << min_operations(nums) << "\n";
    return 0;
}