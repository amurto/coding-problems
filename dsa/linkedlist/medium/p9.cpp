// https://practice.geeksforgeeks.org/problems/leaves-to-dll/1
// Leaves to DLL

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
        left = NULL;
        right = NULL;
    }
};

Node* head;
Node *mergeDLL(Node *root) {
    if (root==NULL)
        return NULL;
    if (root->left == NULL && root->right==NULL) {
        root->right=head;
        if (head != NULL)
            (head)->left=root;
        head = root;
        return NULL;
    }
    root->right = mergeDLL(root->right);
    root->left = mergeDLL(root->left);
    return root;
}

Node * convertToDLL(Node *root){
    head=NULL;
    root = mergeDLL(root);
    return head;
}

int main() {
    return 0;
}