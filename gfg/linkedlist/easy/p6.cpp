// Absolute List Sorting
// https://practice.geeksforgeeks.org/problems/absolute-list-sorting/1

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void sortList(Node **head)
{
    Node *ptr, *prev, *start;
    ptr = *head;
    prev = ptr;
    start = ptr;
    ptr = ptr->next;
    while (ptr != NULL)
    {
        if (ptr->data < 0)
        {
            prev->next = ptr->next;
            ptr->next = start;
            start = ptr;
            ptr = prev->next;
        }
        else
        {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    *head = start;
}

int main()
{
    return 0;
}
