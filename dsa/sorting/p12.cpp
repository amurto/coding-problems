// Quick Select
// Find kth largest element in array

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, int low, int high)
{
    int pivot = nums[high], i = low;
    for (int j = low; j < high; j++)
        if (nums[j] >= pivot)
            swap(nums[i++], nums[j]);
    swap(nums[i], nums[high]);
    return i;
}

int quickselect(vector<int> &nums, int low, int high, int k)
{
    if (low < high)
    {
        int pi = partition(nums, low, high);
        if (pi == k)
            return nums[k];
        else if (pi > k)
            return quickselect(nums, low, pi - 1, k);
        else
            return quickselect(nums, pi + 1, high, k);
    }
    return nums[k];
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> k;
    cout << quickselect(nums, 0, n - 1, k-1) << "\n";
    return 0;
}