// Sort an array of 0s, 1s and 2s

#include <bits/stdc++.h>
using namespace std;

void sort012s(vector<int> &nums)
{
    int i = 0, j = 0, k = nums.size() - 1;
    while (j <= k)
    {
        if (nums[j] == 0)
            swap(nums[i++], nums[j++]);
        else if (nums[j] == 2)
            swap(nums[j], nums[k--]);
        else
            j++;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort012s(nums);
    for (int val : nums)
        cout << val << " ";
    return 0;
}