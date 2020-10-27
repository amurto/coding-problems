# Hashmap

## Structure
```cpp
struct bucket
{
    // self balancing bst can be used for faster operations
    vector<pair<int, int>> b;
    void put(int key, int val)
    {
        for (pair<int, int> &p : b)
            if (p.first == key)
            {
                p.second = val;
                return;
            }
        b.push_back({key, val});
    }
    int get(int key)
    {
        for (pair<int, int> p : b)
            if (p.first == key)
                return p.second;
        return 0;
    }
    bool find(int key)
    {
        for (pair<int, int> p : b)
            if (p.first == key)
                return true;
        return false;
    }
    void display()
    {
        for (pair<int, int> p : b)
            cout << p.first << " -> " << p.second << "\n";
    }
};

// hashset can be implemented similarly
class hashmap
{
private:
    int size;
    bucket *container;

public:
    hashmap(int num)
    {
        // initialize size
        // greater the size, lesser time, greater memory
        size = num;
        container = new bucket[num];
    }
    int hash(int val)
    {
        // easy hash function
        // complicated hash function can be implemented
        return val % size;
    }
    int get(int key)
    {
        return container[hash(key)].get(key);
    }
    void put(int key, int val)
    {
        container[hash(key)].put(key, val);
    }
    bool containsKey(int key)
    {
        return container[hash(key)].find(key);
    }
    void display()
    {
        // key -> value
        for (int i = 0; i < size; i++)
            container[i].display();
    }
};
```

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