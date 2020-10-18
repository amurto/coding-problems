// Sort an array of 0s and 1s

#include <bits/stdc++.h>
using namespace std;

void sort01s(vector<int> &nums)
{
    for (int j = 0, i = 0; j < nums.size(); j++)
        if (nums[j] == 0)
            swap(nums[i++], nums[j]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort01s(nums);
    for (int val : nums)
        cout << val << " ";
    return 0;
}