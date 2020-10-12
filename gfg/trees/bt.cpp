#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    Node(int val, Node *left, Node *right) : data(val), left(left), right(right) {}
};

Node *insertNode(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();
        if (temp->left)
            Q.push(temp->left);
        else
        {
            temp->left = new Node(val);
            return root;
        }
        if (temp->right)
            Q.push(temp->right);
        else
        {
            temp->right = new Node(val);
            return root;
        }
    }
    return root;
}

void deleteNode(Node *root, int val)
{
    if (root == NULL)
        return;
    queue<pair<Node *, Node *>> Q;
    pair<Node *, Node *> lastNode;
    Node *targetNode = NULL;
    Q.push({root, NULL});
    while (!Q.empty())
    {
        lastNode = Q.front();
        if (lastNode.first->data == val)
            targetNode = lastNode.first;
        Q.pop();
        if (lastNode.first->left)
            Q.push({lastNode.first->left, lastNode.first});
        if (lastNode.first->right)
            Q.push({lastNode.first->right, lastNode.first});
    }
    if (targetNode)
    {
        if (lastNode.second)
            if (lastNode.second->left == lastNode.first)
                lastNode.second->left = NULL;
            else if (lastNode.second->right == lastNode.first)
                lastNode.second->right = NULL;
        targetNode->data = lastNode.first->data;
        lastNode.first = NULL;
        delete (lastNode.first);
    }
    return;
}

Node *constructBinaryTree(vector<int> &nodes)
{
    if (nodes.size() == 0)
        return NULL;
    Node *root = new Node(nodes[0]);
    for (int i = 1; i < nodes.size(); i++)
        root = insertNode(root, nodes[i]);
    return root;
}

void LevelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *temp = Q.front();
        cout << temp->data << " ";
        Q.pop();
        if (temp->left)
            Q.push(temp->left);
        if (temp->right)
            Q.push(temp->right);
    }
    cout << "\n";
}

int main()
{
    vector<int> nodes = {7, 11, 12, 10, 15, 9, 8};
    Node *root = constructBinaryTree(nodes);
    LevelOrderTraversal(root);
    deleteNode(root, 11);
    LevelOrderTraversal(root);
    return 0;
}