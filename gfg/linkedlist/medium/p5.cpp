// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
// Intersection Point in Y Shapped Linked Lists

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

int countNodes(Node* head) {
    int c=0;
    while (head!=NULL) {
        c++;
        head=head->next;
    }
    return c;
}

int intersectPoint(Node* head1, Node* head2)
{
    int c1=countNodes(head1), c2=countNodes(head2);
    int d = abs(c1-c2);
    if (c1>c2)
        while (d-- > 0)
            head1=head1->next;
    else
        while (d-->0)
            head2=head2->next;
    
    while (head1 && head2) {
        if (head1==head2)
            return head1->data;
        head1=head1->next;
        head2=head2->next;
    }
    return -1;
}

int main() {
    return 0;
}