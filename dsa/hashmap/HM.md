# Hashmap

## Structure

## Table of Contents

- [Highest Frequency Character](#hfc)
- [Intersection of Two Arrays](#intersect-i)
- [Intersection of Two Arrays II](#intersect-ii)

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