// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
// Remove loop in Linked List

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

void removeLoop(Node* head)
{
    if(!head) return;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow )
    {
        if( !fast || !fast->next ) return;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    int size = 1;
    fast = fast->next;
    while( fast != slow )
    {
        size++;
        fast = fast->next;
    }
    
    slow = head;
    fast = head;
    for(int i=0; i<size-1; i++)
        fast = fast->next;
    
    while( fast->next != slow )
    {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = NULL;
}

int main() {
    return 0;
}