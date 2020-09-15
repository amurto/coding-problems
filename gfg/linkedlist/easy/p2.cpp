// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
// Reverse a linked list

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

// Recursion
Node *reverseList(Node *head)
{
    if (head->next==NULL)
        return head;
    Node* cur = reverseList(head->next);
    head->next->next = head;
    head->next=NULL;
    return cur;
}

// Iteration
Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}

int main()
{
    return 0;
}