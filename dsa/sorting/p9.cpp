// Selection Sort

#include <bits/stdc++.h>
using namespace std;

void selectionsort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (nums[j] < nums[minIdx])
                minIdx = j;
        swap(nums[i], nums[minIdx]);
    }
}

vector<int> sortArray(vector<int> &nums)
{
    selectionsort(nums);
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