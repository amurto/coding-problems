// Insertion Sort

#include <bits/stdc++.h>
using namespace std;

void insertionsort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int cur = nums[i], j = i - 1;
        while (j >= 0 && nums[j] > cur)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = cur;
    }
}

vector<int> sortArray(vector<int> &nums)
{
    insertionsort(nums);
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