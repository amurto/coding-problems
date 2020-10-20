# Stack and Queue

## Table of Contents

- [Duplicate Brackets](#duplicate-brackets)
- [Valid Parentheses](#valid-parentheses)
- [Next Greater Element I](#ngt-i)
- [Stock span problem](#stock-span)
- [Largest Rectangle in Histogram](#largest-rectangle-in-histogram)
- [Sliding Window Maximum](#https://leetcode.com/problems/sliding-window-maximum/)

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

<div id="stock-span">

## Stock span problem

https://practice.geeksforgeeks.org/problems/stock-span-problem/0

```cpp
vector<int> getStockSpan(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> STACK;
    for (int i = 0; i < n; i++)
    {
        while (!STACK.empty() && arr[STACK.top()] <= arr[i])
            STACK.pop();
        if (STACK.empty())
            ans[i] = i + 1;
        else
            ans[i] = i - STACK.top();
        STACK.push(i);
    }
    return ans;
}
```

</div>

<div id="largest-rectangle-in-histogram">

## Largest Rectangle in Histogram

https://leetcode.com/problems/largest-rectangle-in-histogram/

```cpp
// Find previous and next smaller element of every element and calculate area as height of element * (next - prev - 1)
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size(), MAX = 0, h, w;
    if (n == 0)
        return MAX;
    stack<int> STACK;
    heights;
    STACK.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!STACK.empty() && heights[STACK.top()] > heights[i])
        {
            h = heights[STACK.top()];
            STACK.pop();
            w = STACK.empty() ? -1 : STACK.top();
            MAX = max(MAX, h * (i - w - 1));
        }
        STACK.push(i);
    }

    // Checking if any elements left and handling corner case where n = 1
    while (!STACK.empty())
    {
        h = heights[STACK.top()];
        STACK.pop();
        w = STACK.empty() ? -1 : STACK.top();
        MAX = max(MAX, h * (n - w - 1));
    }
    return MAX;
}
```

</div>

<div id="sliding-window-maximum">

## Sliding Window Maximum

https://leetcode.com/problems/sliding-window-maximum/

```cpp
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> window;
    deque<int> DQ;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!DQ.empty() && DQ.front() == i - k)
            DQ.pop_front();
        while (!DQ.empty() && nums[DQ.back()] < nums[i])
            DQ.pop_back();
        DQ.push_back(i);
        if (i - k >= -1)
            window.push_back(nums[DQ.front()]);
    }
    return window;
}
```

</div>
