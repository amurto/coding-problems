// https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1
// Binary Tree to CDLL

#include <bits/stdc++.h>
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

Node *merge(Node *L, Node *R)
{
    if (L == NULL)
        return R;
    if (R == NULL)
        return L;
    Node *LL = L->left;
    Node *RL = R->left;
    LL->right = R;
    R->left = LL;
    RL->right = L;
    L->left = RL;
    return L;
}

Node *bTreeToCList(Node *root)
{
    if (root == NULL)
        return NULL;
    Node *L = bTreeToCList(root->left);
    Node *R = bTreeToCList(root->right);

    root->left = root->right = root;
    return merge(merge(L, root), R);
}

int main()
{
    return 0;
}