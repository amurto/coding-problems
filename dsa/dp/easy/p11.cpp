// https://leetcode.com/problems/house-robber/
// House Robber

#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    int notprev = 0, prev = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int cur = max(prev, notprev + nums[i]);
        notprev = prev;
        prev = cur;
    }
    return prev;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << rob(nums) << "\n";
    return 0;
}