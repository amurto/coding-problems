#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int getPairsCount(vector<int> nums, int sum)
{
    unordered_map<int, int> MAP;
    int pairs = 0;
    for (int val : nums)
    {
        pairs += MAP[sum - val];
        MAP[val]++;
    }
    return pairs;
}

int getPairsCountSort(vector<int> nums, int sum)
{
    int pairs = 0, beg = 0, end = nums.size() - 1;
    sort(nums.begin(), nums.end());
    while (beg < end)
    {
        if (nums[beg] + nums[end] > sum)
            end--;
        else if (nums[beg] + nums[end] < sum)
            beg++;
        else
        {
            int cbeg = beg, x = nums[beg], cend = end, y = nums[end];
            while (beg < end && nums[beg] == x)
                beg++;
            while (end >= beg && nums[end] == y)
                end--;
            if (x == y)
            {
                int temp = beg - cbeg + cend - end - 1;
                pairs += temp * (temp + 1) / 2;
            }
            else
                pairs += (beg - cbeg) * (cend - end);
        }
    }
    return pairs;
}

int main()
{
    int n, sum;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> sum;
    cout << getPairsCountSort(nums, sum) << "\n";
    return 0;
}