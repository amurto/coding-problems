// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
// Reverse a Linked List in groups of given size

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

Node *reverse (Node *head, int k)
{ 
    if (head==NULL)
        return NULL;
    Node *prev = NULL, *cur = head;
    int c = k;
    while (c-- > 0 && cur != NULL) {
        Node *temp = cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    head->next=reverse(cur, k);
    return prev;
}

int main() {
    return 0;
}