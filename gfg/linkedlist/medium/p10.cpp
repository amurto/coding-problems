// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
// Clone a linked list with next and random pointer

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class Node
{
public:
    int data;
    Node *next;
    Node *arb;
    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
    
Node *copyList(Node *head) {
    Node *cur = head, *next = head->next, *fast;
    while (cur) {
        Node* temp = cur->next;
        Node *newNode = new Node(cur->data);
        cur->next = newNode;
        newNode->next = temp;
        cur = temp;
    }
    cur = head;
    while (cur) {
        if (cur->arb)
            cur->next->arb = cur->arb->next;
        cur=cur->next->next;
    }
    Node* cloned = head->next;
    cur = head, fast=head->next;
    while (cur) {
        cur->next=cur->next->next;
        cur=cur->next;
        if (cur) {
            fast->next=cur->next;
            fast=fast->next;
        }
    }
    return cloned;
}

int main() {
    return 0;
}