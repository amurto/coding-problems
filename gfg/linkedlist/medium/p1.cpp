// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// Flattening a Linked List

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *merge(Node *ptr1, Node *ptr2)
{
    if (ptr1 == NULL)
        return ptr2;
    if (ptr2 == NULL)
        return ptr1;
    if (ptr1->data < ptr2->data)
    {
        ptr1->bottom = merge(ptr1->bottom, ptr2);
        return ptr1;
    }
    else
    {
        ptr2->bottom = merge(ptr1, ptr2->bottom);
        return ptr2;
    }
}

Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;
    Node *start = root, *ptr = root->next;
    while (ptr != NULL)
    {
        start = merge(start, ptr);
        ptr = ptr->next;
    }
    return start;
}

int main()
{
    return 0;
}