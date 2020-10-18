// https://practice.geeksforgeeks.org/problems/quicksort-on-doubly-linked-list/1
// QuickSort on Doubly Linked List

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

Node *partition(Node *l, Node *h)
{
    int pivot = h->data;
    Node *i = l;
    for (Node *j = l; j != h; j = j->next)
    {
        if (j->data <= pivot)
        {
            // swap(&(i->data), &(j->data));
            i = i->next;
        }
    }
    // swap(&(i->data), &(h->data));
    return i;
}

int main()
{
    return 0;
}