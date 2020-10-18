// Union of Two Linked Lists
// https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1

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

Node* makeUnion(Node* head1, Node* head2)
{
    set<int> SET;
    while (head1!=NULL) {
        SET.insert(head1->data);
        head1=head1->next;
    }
    while (head2!=NULL) {
        SET.insert(head2->data);
        head2=head2->next;
    }
    head1=NULL;
    for (auto it=SET.begin(); it!=SET.end(); it++) {
        Node* newNode = new Node(*it);
        if (head1==NULL) {
            head1=newNode;
            head2=head1;
        } else {
            head1->next=newNode;
            head1=head1->next;
        }
    }
    return head2;
}

int main() {
    return 0;
}