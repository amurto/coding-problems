// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
// Detect Loop in linked list

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

bool detectLoop(Node* head)
{
    if (head==NULL)
        return false;
    Node *slow=head, *fast=head;
    while (fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast)
            return true;
    }
    return false;
}

int main() {
    return 0;
}