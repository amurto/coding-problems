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

void InorderTraversalRecursion(Node *root)
{
    if (root == NULL)
        return;
    InorderTraversalRecursion(root->left);
    cout << root->data << " ";
    InorderTraversalRecursion(root->right);
}

void PreorderTraversalRecursion(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreorderTraversalRecursion(root->left);
    PreorderTraversalRecursion(root->right);
}

void PostorderTraversalRecursion(Node *root)
{
    if (root == NULL)
        return;
    PostorderTraversalRecursion(root->left);
    PostorderTraversalRecursion(root->right);
    cout << root->data << " ";
}

void InorderTraversalStack(Node *root)
{
    stack<Node *> STACK;
    Node *cur = root;
    while (cur || !STACK.empty())
    {
        while (cur)
        {
            STACK.push(cur);
            cur = cur->left;
        }
        cur = STACK.top();
        cout << cur->data << " ";
        STACK.pop();
        cur = cur->right;
    }
    cout << "\n";
}

void PreorderTraversalStack(Node *root)
{
    stack<Node *> STACK;
    Node *cur = root;
    while (cur || !STACK.empty())
    {
        while (cur)
        {
            cout << cur->data << " ";
            STACK.push(cur);
            cur = cur->left;
        }
        cur = STACK.top();
        STACK.pop();
        cur = cur->right;
    }
    cout << "\n";
}

void PostorderTraversalStack(Node *root)
{
    stack<Node *> STACK;
    Node *cur = root;
    while (cur || !STACK.empty())
    {
        while (cur)
        {
            STACK.push(cur);
            cur = cur->left;
        }
        cur = STACK.top();
        if (cur->right)
            cur = cur->right;
        else
        {
            STACK.pop();
            cout << cur->data << " ";
            while (!STACK.empty() && STACK.top()->right == cur)
            {
                cur = STACK.top();
                cout << cur->data << " ";
                STACK.pop();
            }
            cur = NULL;
        }
    }
}

int main()
{
    vector<int> nodes = {10, 8, 2, 3, 5, 2};
    Node *root = constructBinaryTree(nodes);
    PostorderTraversalRecursion(root);
    cout << "\n";
    PostorderTraversalStack(root);
    return 0;
}