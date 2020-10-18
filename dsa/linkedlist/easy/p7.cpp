// https://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1
// Delete Middle of Linked List

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

Node *deleteMid(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *ptr1 = head, *ptr2 = head, *prev;
    while (ptr2 != NULL && ptr2->next != NULL)
    {
        prev = ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    prev->next = ptr1->next;
    ptr1 = NULL;
    return head;
}

int main()
{
    return 0;
}