# Stack and Queue

## Table of Contents

- [Duplicate Brackets](#duplicate-brackets)
- [Valid Parentheses](#valid-parentheses)
- [Next Greater Element I](#ngt-i)
- [Stock span problem](#stock-span)
- [Largest Rectangle in Histogram](#largest-rectangle-in-histogram)
- [Sliding Window Maximum](#sliding-window-maximum)
- [Infix, Prefix and Postfix](#infix-prefix-postfix)

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

<div id="infix-prefix-postfix">

## Infix, Prefix and Postfix

``` cpp
bool isOperator(char ch)
{
    return (!isalpha(ch) && !isdigit(ch));
}

int priority(char ch)
{
    if (ch == '-' || ch == '+')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    return 0;
}

int operation(int v1, int v2, char ch)
{
    if (ch == '+')
        return v1 + v2;
    else if (ch == '-')
        return v1 - v2;
    else if (ch == '*')
        return v1 * v2;
    else if (ch == '/')
        return v1 / v2;
    else if (ch == '^')
        return v1 ^ v2;
    return -1;
}

string getString(char ch)
{
    string s(1, ch);
    return s;
}

// Infix Evaluation
int solveInfix(string str)
{
    str = "(" + str + ")";
    stack<int> nums;
    stack<char> ops;
    for (char ch : str)
    {
        if (ch == '(')
            ops.push(ch);
        else if (isdigit(ch))
            nums.push(ch - '0');
        else if (ch == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int v = nums.top();
                nums.pop();
                int ans = operation(nums.top(), v, ops.top());
                nums.pop();
                ops.pop();
                nums.push(ans);
            }
            ops.pop();
        }
        else if (isOperator(ch))
        {
            while (!ops.empty() && ops.top() != '(' && priority(ops.top()) >= priority(ch))
            {
                int v = nums.top();
                nums.pop();
                int ans = operation(nums.top(), v, ops.top());
                nums.pop();
                ops.pop();
                nums.push(ans);
            }
            ops.push(ch);
        }
    }
    return nums.top();
}

// Infix Conversions

// Infix to Prefix
string InfixToPrefix(string str)
{
    // To extract all characters from stack at the end
    str = "(" + str + ")";
    stack<char> ops;
    stack<string> prefix;
    for (char ch : str)
    {
        if (ch == '(')
            ops.push(ch);
        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            prefix.push(getString(ch));
        else if (ch == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                string v2 = prefix.top();
                prefix.pop();
                string v1 = prefix.top();
                prefix.pop();
                char op = ops.top();
                ops.pop();
                prefix.push(op + v1 + v2);
            }
            ops.pop();
        }
        else if (isOperator(ch))
        {
            while (!ops.empty() && ops.top() != '(' && priority(ops.top()) >= priority(ch))
            {
                string v2 = prefix.top();
                prefix.pop();
                string v1 = prefix.top();
                prefix.pop();
                char op = ops.top();
                ops.pop();
                prefix.push(op + v1 + v2);
            }
            ops.push(ch);
        }
    }
    return prefix.top();
}

// Infix to Postfix
string InfixToPostfix(string str)
{
    // To extract all characters from stack at the end
    str = "(" + str + ")";
    string postfix = "";
    stack<char> ops;
    for (char ch : str)
    {
        if (ch == '(')
            ops.push(ch);
        else if (isalpha(ch) || isdigit(ch))
            postfix += ch;
        else if (ch == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                postfix += ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else if (isOperator(ch))
        {
            while (!ops.empty() && priority(ops.top()) >= priority(ch))
            {
                postfix += ops.top();
                ops.pop();
            }
            ops.push(ch);
        }
    }
    return postfix;
}

// Prefix Evaluation
int solvePrefix(string str)
{
    stack<int> nums;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (isOperator(str[i]))
        {
            int v1 = nums.top();
            nums.pop();
            int v2 = nums.top();
            nums.pop();
            nums.push(operation(v1, v2, str[i]));
        }
        else
            nums.push(str[i] - '0');
    }
    return nums.top();
}

// Prefix Conversions

// Prefix to Infix
string PrefixToInfix(string str)
{
    stack<string> infix;
    for (int i = str.size() - 1; i >= 0; i--)
    {

        if (isOperator(str[i]))
        {
            string v1 = infix.top();
            infix.pop();
            string v2 = infix.top();
            infix.pop();
            infix.push('(' + v1 + str[i] + v2 + ')');
        }
        else
            infix.push(getString(str[i]));
    }
    return infix.top();
}

// Prefix to Postfix
string PrefixToPostfix(string str)
{
    stack<string> postfix;
    for (int i = str.size() - 1; i >= 0; i--)
    {

        if (isOperator(str[i]))
        {
            string v1 = postfix.top();
            postfix.pop();
            string v2 = postfix.top();
            postfix.pop();
            postfix.push(v1 + v2 + str[i]);
        }
        else
            postfix.push(getString(str[i]));
    }
    return postfix.top();
}

// Postfix Evaluation
int solvePostfix(string str)
{
    stack<int> nums;
    for (char ch : str)
    {
        if (isOperator(ch))
        {
            int v2 = nums.top();
            nums.pop();
            int v1 = nums.top();
            nums.pop();
            nums.push(operation(v1, v2, ch));
        }
        else
            nums.push(ch - '0');
    }
    return nums.top();
}

// Postfix Conversion

// Postfix to Infix
string PostfixToInfix(string str)
{
    stack<string> infix;
    for (char ch : str)
    {

        if (isOperator(ch))
        {
            string v2 = infix.top();
            infix.pop();
            string v1 = infix.top();
            infix.pop();
            infix.push('(' + v1 + ch + v2 + ')');
        }
        else
            infix.push(getString(ch));
    }
    return infix.top();
}

// Postfix to Prefix
string PostfixToPrefix(string str)
{
    stack<string> postfix;
    for (char ch : str)
    {

        if (isOperator(ch))
        {
            string v2 = postfix.top();
            postfix.pop();
            string v1 = postfix.top();
            postfix.pop();
            postfix.push(ch + v1 + v2);
        }
        else
            postfix.push(getString(ch));
    }
    return postfix.top();
}
```

</div>