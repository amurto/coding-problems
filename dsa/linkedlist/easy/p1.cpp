// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
// Merge Sort for Linked List

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

void insert(Node **root, int v)
{
    Node *temp = new Node(v);
    Node *ptr;
    temp->next = NULL;
    if (*root == NULL)
        *root = temp;
    else
    {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

Node *arrayToList(int n)
{
    Node *root = NULL;
    int v;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        insert(&root, v);
    }
    return root;
}

void display(Node *root)
{
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
}

Node *merge(Node *l1, Node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->data < l2->data)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *mid1 = head;
    Node *end = head->next;
    while (end && end->next)
    {
        mid1 = mid1->next;
        end = end->next->next;
    }
    Node *mid2 = mid1->next;
    mid1->next = NULL;
    return merge(mergeSort(head), mergeSort(mid2));
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, v;
        cin >> n;
        Node *root = arrayToList(n);
        root = mergeSort(root);
        display(root);
    }
    return 0;
}