// Merge Sort 

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> arr(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (nums[i] < nums[j])
            arr[k++] = nums[i++];
        else
            arr[k++] = nums[j++];
    }
    while (i <= mid)
        arr[k++] = nums[i++];
    while (j <= high)
        arr[k++] = nums[j++];
    for (int idx = 0; idx < arr.size(); idx++)
        nums[low + idx] = arr[idx];
}

void mergesort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(nums, low, mid);
        mergesort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

vector<int> sortArray(vector<int> &nums)
{
    mergesort(nums, 0, nums.size() - 1);
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