// https://practice.geeksforgeeks.org/problems/reorder-list/1
// Reorder List

#include<bits/stdc++.h>
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

Node *reverseList(Node *cur) {
    if (cur==NULL || cur->next==NULL)
        return cur;
    Node* newHead = reverseList(cur->next);
    cur->next->next=cur;
    cur->next=NULL;
    return newHead;
}

void reorderList(Node* head) {
    Node *fast=head, *slow=head, *temp1, *temp2;
    while (fast && fast->next) {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *second = reverseList(slow->next);
    slow->next=NULL;
    while (head && second) {
        temp1 = head->next;
        temp2 = second->next;
        head->next=second;
        second->next=temp1;
        head=temp1;
        second=temp2;
    }
}

int main() {
    return 0;
}