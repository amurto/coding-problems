// https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1
// Implement two stacks in an array

#include <bits/stdc++.h>
using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};

void twoStacks ::push1(int x)
{
    // pushing element to the top of first stack
    if (top1 < top2 - 1)
        arr[++top1] = x;
}

void twoStacks ::push2(int x)
{
    // pushing element to the top of second stop
    if (top1 < top2 - 1)
        arr[--top2] = x;
}

int twoStacks ::pop1()
{
    // removing element from the top of first stack
    if (top1 == -1)
        return -1;
    return arr[top1--];
}

int twoStacks ::pop2()
{
    // removing element from the top of second stack
    if (top2 == size)
        return -1;
    return arr[top2++];
}

int main()
{
    return 0;
}