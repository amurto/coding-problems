#include <bits/stdc++.h>
using namespace std;

int waysToMakeFair(vector<int> &nums)
{
    int n = nums.size(), ways = 0;
    vector<int> suf(n);
    for (int i = n - 1; i >= 0; i--)
    {
        suf[i] = nums[i];
        if (i + 2 < n)
            suf[i] += suf[i + 2];
    }
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        int ne = even, no = odd;
        if (i + 1 < n)
        {
            if (i % 2 == 0)
                ne += suf[i + 1];
            else
                no += suf[i + 1];
        }
        if (i + 2 < n)
        {
            if (i % 2 == 1)
                ne += suf[i + 2];
            else
                no += suf[i + 2];
        }
        if (ne == no)
            ways++;
        if (i % 2 == 0)
            even += nums[i];
        else
            odd += nums[i];
    }
    return ways;
}

int main()
{
    vector<int> nums = {1, 1, 1};
    cout << waysToMakeFair(nums) << "\n";
    return 0;
}