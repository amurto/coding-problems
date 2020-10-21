// https://practice.geeksforgeeks.org/problems/number-following-a-pattern/0
// Number following a pattern

#include <bits/stdc++.h>
using namespace std;

vector<int> NumberPattern(string str)
{
    stack<int> STACK;
    vector<int> seq;
    int cur = 0;
    for (char ch : str)
    {
        if (ch == 'I')
        {
            STACK.push(++cur);
            while (!STACK.empty())
            {
                seq.push_back(STACK.top());
                STACK.pop();
            }
        }
        else
            STACK.push(++cur);
    }
    STACK.push(++cur);
    while (!STACK.empty())
    {
        seq.push_back(STACK.top());
        STACK.pop();
    }
    return seq;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string str;
        cin >> str;
        vector<int> seq = NumberPattern(str);
        for (int val : seq)
            cout << val;
        cout << "\n";
    }
    return 0;
}