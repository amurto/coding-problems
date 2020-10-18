// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Find Minimum in Rotated Sorted Array

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int beg = 0, end = nums.size() - 1;
    if (nums[end] >= nums[beg])
        return nums[beg];
    while (beg <= end)
    {
        int mid = beg + (end - beg) / 2;
        if (nums[mid] > nums[mid + 1])
            return nums[mid + 1];
        if (nums[mid] < nums[mid - 1])
            return nums[mid];
        if (nums[mid] > nums[0])
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << findMin(nums) << "\n";
    return 0;
}