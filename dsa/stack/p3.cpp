// https://leetcode.com/problems/next-greater-element-i/
// Next Greater Element I

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    if (n1 == 0 || n2 == 0)
        return {};
    stack<int> STACK;
    vector<int> ans(n1, -1), MAP(100001, -1);
    for (int i = 0; i < n1; i++)
        MAP[nums1[i]] = i;
    STACK.push(nums2[nums2.size() - 1]);
    for (int i = n2 - 2; i >= 0; i--)
    {
        while (!STACK.empty() && STACK.top() <= nums2[i])
            STACK.pop();
        if (MAP[nums2[i]] >= 0)
        {
            if (STACK.empty())
                ans[MAP[nums2[i]]] = -1;
            else
                ans[MAP[nums2[i]]] = STACK.top();
        }
        STACK.push(nums2[i]);
    }
    return ans;
}

int main()
{
    int n1, n2;
    cin >> n1;
    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++)
        cin >> nums1[i];
    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++)
        cin >> nums2[i];
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (int val : ans)
        cout << val << "\n";
    return 0;
}