#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    string str;
    getline(cin, str);
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return 0;
}