# Hashmap

## Structure

## Table of Contents

- [Highest Frequency Character](#hfc)
- [Intersection of Two Arrays](#intersect-i)
- [Intersection of Two Arrays II](#intersect-ii)
- [Longest Consecutive Sequence](#longest-consecutive-sequence)

<div id="hfc">

## Highest Frequency Character
```cpp
char HighestFrequencyCharacter(string str)
{
    unordered_map<char, int> MAP;
    int MAX = 0;
    for (char ch : str)
    {
        MAP[ch]++;
        MAX = max(MAX, MAP[ch]);
    }
    char ans = '0';
    for (auto it = MAP.begin(); it != MAP.end(); it++)
        if (it->second == MAX)
            return it->first;
    return '0';
}
```
</div>

<div id="intersect-i">

## Intersection of Two Arrays
https://leetcode.com/problems/intersection-of-two-arrays/
```cpp
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    unordered_set<int> SET;
    for (int val : nums1)
        SET.insert(val);

    for (int val : nums2)
        if (SET.find(val) != SET.end())
        {
            SET.erase(val);
            res.push_back(val);
        }
    return res;
}
```
</div>

<div id="intersect-ii">

## Intersection of Two Arrays II
https://leetcode.com/problems/intersection-of-two-arrays-ii/
```cpp
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    unordered_map<int, int> MAP;
    for (int val : nums1)
        MAP[val]++;
    for (int val : nums2)
        if (MAP[val] > 0)
        {
            res.push_back(val);
            MAP[val]--;
        }
    return res;
}
```
</div>

<div id="longest-consecutive-sequence">

## Longest Consecutive Sequence
https://leetcode.com/problems/longest-consecutive-sequence/
```cpp
// set implementation 
// O(n) time and O(n) space
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
```
</div>