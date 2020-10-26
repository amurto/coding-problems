// https://leetcode.com/problems/longest-consecutive-sequence/
// Longest Consecutive Sequence

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> SET(nums.begin(), nums.end());
    int streak = 0;
    for (int val : nums)
    {
        if (SET.find(val) != SET.end())
        {
            int cnt = 1;
            SET.erase(val);
            int L = val, R = val;
            while (L > INT_MIN)
            {
                L--;
                if (SET.find(L) != SET.end())
                    cnt++;
                else
                    break;
                SET.erase(L);
            }
            while (R < INT_MAX)
            {
                R++;
                if (SET.find(R) != SET.end())
                    cnt++;
                else
                    break;
                SET.erase(R);
            }
            streak = max(streak, cnt);
        }
    }
    return streak;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << longestConsecutive(nums) << "\n";
    return 0;
}