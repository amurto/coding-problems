// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/0
// The Celebrity Problem

#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> STACK;
    for (int i = n - 1; i >= 0; i--)
        STACK.push(i);
    while (STACK.size() > 1)
    {
        int c1 = STACK.top();
        STACK.pop();
        int c2 = STACK.top();
        STACK.pop();
        if (M[c1][c2] == 1)
            STACK.push(c2);
        else
            STACK.push(c1);
    }
    int celeb = STACK.top();
    STACK.pop();
    for (int i = 0; i < n; i++)
        if (i != celeb && (M[i][celeb] == 0 || M[celeb][i] == 1))
            return -1;
    return celeb;
}

int main()
{
    int n;
    cin >> n;
    string str;
    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
    cout << celebrity(M, n) << "\n";
    return 0;
}