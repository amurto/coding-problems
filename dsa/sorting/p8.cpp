// Bubble Sort

#include <bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &nums)
{
    // n passes
    int n = nums.size();
    for (int pass = n - 1; pass >= 0; pass--)
        for (int j = 0; j < pass; j++)
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
}

void modifiedbubblesort(vector<int> &nums)
{
    // n passes
    int n = nums.size();
    for (int pass = n - 1; pass >= 0; pass--)
    {
        bool isSort = true;
        for (int j = 0; j < pass; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                isSort = false;
                swap(nums[j], nums[j + 1]);
            }
        }
        if (isSort)
            break;
    }
}

vector<int> sortArray(vector<int> &nums)
{
    bubblesort(nums);
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