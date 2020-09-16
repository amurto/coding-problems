// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
// Reverse a Doubly Linked List

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *reverseDLL(Node *head)
{
    Node *cur = head;
    Node *prev = NULL;
    while (cur != NULL)
    {
        cur->prev = cur->next;
        cur->next = prev;
        prev = cur;
        cur = cur->prev;
    }
    return prev;
}

int main()
{
    return 0;
}