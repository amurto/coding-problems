// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
// Binary Tree to DLL

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right =NULL;
    }
};

void mergeDLL(Node *root, Node **head) {
    if (root==NULL)
        return;
    mergeDLL(root->right, head);
    root->right = *head;
    if ((*head)!=NULL)
        (*head)->left=root;
    *head = root;
    mergeDLL(root->left, head);
}

Node * bToDLL(Node *root)
{
    Node *head=NULL;
    mergeDLL(root, &head);
    return head;
}

int main() {
    return 0;
}