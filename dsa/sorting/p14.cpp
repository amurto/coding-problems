// Radix Sort

#include <bits/stdc++.h>
using namespace std;

void countsort(vector<int> &nums, int place)
{
    int n = nums.size();
    vector<int> ans(n);
    vector<int> MAP(10);
    for (int val : nums)
        MAP[(val / place) % 10]++;

    for (int i = 1; i < 10; i++)
        MAP[i] += MAP[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        ans[MAP[(nums[i] / place) % 10] - 1] = nums[i];
        MAP[(nums[i] / place) % 10]--;
    }
    for (int i = 0; i < nums.size(); i++)
        nums[i] = ans[i];
}

void radixsort(vector<int> &nums)
{
    int MAX = INT_MIN;
    for (int val : nums)
        MAX = max(MAX, val);
    for (int place = 1; MAX / place > 0; place *= 10)
        countsort(nums, place);
}

vector<int> sortArray(vector<int> &nums)
{
    radixsort(nums);
    return nums;
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