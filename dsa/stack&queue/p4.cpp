// https://practice.geeksforgeeks.org/problems/stock-span-problem/0
// Stock span problem

#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans = getStockSpan(arr);
    for (int val : ans)
        cout << val << " ";
    return 0;
}