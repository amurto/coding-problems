// https://www.geeksforgeeks.org/find-expression-duplicate-parenthesis-not/
// Duplicate Brackets

#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    string str;
    getline(cin, str); 
    containsDuplicateBrackets(str) ? cout << "true" : cout << "false";
    return 0;
}