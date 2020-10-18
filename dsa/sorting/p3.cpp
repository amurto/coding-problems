// Quick Sort

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, int low, int high)
{
    int pivot = nums[high], i = low;
    for (int j = low; j < high; j++)
        if (nums[j] < pivot)
            swap(nums[i++], nums[j]);
    swap(nums[i], nums[high]);
    return i;
}

void quicksort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int pi = partition(nums, low, high);
        quicksort(nums, low, pi - 1);
        quicksort(nums, pi + 1, high);
    }
}

vector<int> sortArray(vector<int> &nums)
{
    quicksort(nums, 0, nums.size() - 1);
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