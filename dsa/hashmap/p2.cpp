// https://leetcode.com/problems/intersection-of-two-arrays/
// Intersection of Two Arrays

#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int n1, n2;
    cin >> n1;
    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++)
        cin >> nums1[i];
    cin >> n2;
    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++)
        cin >> nums2[i];
    vector<int> res = intersection(nums1, nums2);
    for (int val : res)
        cout << val << " ";
    return 0;
}