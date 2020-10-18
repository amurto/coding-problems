// https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1
// Deletion and Reverse in Linked List

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

void deleteNode(Node **head, int key)
{
    Node *prev = *head;
    Node *ptr = prev->next;
    while (ptr->data != key)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    ptr = NULL;
}

void reverse(Node **head_ref)
{
    stack<Node *> STACK;
    Node *head = *head_ref;
    Node *ptr = head;
    do
    {
        STACK.push(ptr);
        ptr = ptr->next;
    } while (ptr != head);

    Node *temp = STACK.top();
    Node *memo = temp;
    STACK.pop();

    while (!STACK.empty())
    {
        temp->next = STACK.top();
        temp = temp->next;
        STACK.pop();
    }
    temp->next = memo;
    *head_ref = memo;
}

int main()
{
    return 0;
}