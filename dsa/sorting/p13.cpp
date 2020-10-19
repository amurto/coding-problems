// Count Sort

#include <bits/stdc++.h>
using namespace std;

vector<int> countsort(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    // Find Min, Max
    int MIN = INT_MAX, MAX = INT_MIN;
    for (int val : nums)
    {
        MIN = min(MIN, val);
        MAX = max(MAX, val);
    }
    vector<int> MAP(MAX - MIN + 1, 0);
    for (int val : nums)
        MAP[val - MIN]++;

    for (int i = 1; i < MAX - MIN + 1; i++)
        MAP[i] += MAP[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        ans[MAP[nums[i] - MIN] - 1] = nums[i];
        MAP[nums[i] - MIN]--;
    }
    return ans;
}

vector<int> sortArray(vector<int> &nums)
{
    return countsort(nums);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> ans = sortArray(nums);
    for (int v : ans)
        cout << v << " ";
    return 0;
}