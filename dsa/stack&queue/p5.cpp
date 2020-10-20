// https://leetcode.com/problems/largest-rectangle-in-histogram/
// Largest Area Histogram

#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];
    cout << largestRectangleArea(heights) << "\n";
    return 0;
}