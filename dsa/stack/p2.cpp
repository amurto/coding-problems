// https://leetcode.com/problems/valid-parentheses/
// Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    string str;
    getline(cin, str);
    isValid(str) ? cout << "true" : cout << "false";
    return 0;
}