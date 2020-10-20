# Stack

## Table of Contents

- [Duplicate Brackets](#duplicate-brackets)
- [Valid Parentheses](#valid-parentheses)
- [Next Greater Element I](#ngt-i)

<div id="duplicate-brackets">

## Duplicate Brackets
https://www.geeksforgeeks.org/find-expression-duplicate-parenthesis-not/
```cpp
bool containsDuplicateBrackets(string str)
{
    stack<char> STACK;
    for (char ch : str)
    {
        if (ch == ')')
        {
            if (STACK.top() == '(')
                return true;
            else
            {
                while (STACK.top() != '(')
                    STACK.pop();
                STACK.pop();
            }
        }
        else
            STACK.push(ch);
    }
    return false;
}
```
</div>

<div id="">

## Valid Parentheses
https://leetcode.com/problems/valid-parentheses/
```cpp
bool isValid(string str)
{
    stack<char> STACK;
    for (char ch : str)
    {
        if (ch == ')' || ch == '}' || ch == ']')
        {
            if (STACK.empty() || (ch == ')' && STACK.top() != '(') || (ch == '}' && STACK.top() != '{') || (ch == ']' && STACK.top() != '['))
                return false;
            STACK.pop();
        }
        else if (ch == '(' || ch == '{' || ch == '[')
            STACK.push(ch);
    }
    if (STACK.empty())
        return true;
    return false;
}
```
</div>

<div id="ngt-i">

## Next Greater Element I
https://leetcode.com/problems/next-greater-element-i/
```cpp
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
```
</div>