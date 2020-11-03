// Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> window;
    deque<int> DQ;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!DQ.empty() && DQ.front() == i - k)
            DQ.pop_front();
        while (!DQ.empty() && nums[DQ.back()] < nums[i])
            DQ.pop_back();
        DQ.push_back(i);
        if (i - k >= -1)
            window.push_back(nums[DQ.front()]);
    }
    return window;
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> k;
    vector<int> ans = maxSlidingWindow(nums, k);
    for (int val : ans)
        cout << val << "\n";
    return 0;
}