// https://leetcode.com/problems/min-stack/
// Min Stack

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<int> st1;
    stack<int> st2;

public:
    void push(int x)
    {
        if (st1.empty() || x <= st2.top())
            st2.push(x);
        st1.push(x);
    }

    void pop()
    {
        if (st1.empty())
            return;
        if (st1.top() == st2.top())
            st2.pop();
        st1.pop();
    }

    int top()
    {
        if (st1.empty())
            return -1;
        return st1.top();
    }

    int getMin()
    {
        if (st2.empty())
            return -1;
        return st2.top();
    }
};

int main()
{
    /**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
    return 0;
}