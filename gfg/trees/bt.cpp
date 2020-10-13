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

int TreeHeight(Node *root)
{
    if (root)
        return 1 + max(TreeHeight(root->left), TreeHeight(root->right));
    return 0;
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

void LevelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    // BFS with Queue
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

void ReverseLevelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> Q;
    Q.push(root);
    vector<int> ans;
    while (!Q.empty())
    {
        // At a certain iteration, all nodes in a queue belong to the same level
        Node *temp = Q.front();
        ans.push_back(temp->data);
        Q.pop();
        if (temp->right)
            Q.push(temp->right);
        if (temp->left)
            Q.push(temp->left);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    cout << "\n";
}

void printLevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 0)
        cout << root->data << " ";
    else
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void LevelOrderTraversalRecursion(Node *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < TreeHeight(root); i++)
        printLevel(root, i);
}

void ReverseLevelOrderTraversalRecursion(Node *root)
{
    if (root == NULL)
        return;
    for (int i = TreeHeight(root) - 1; i >= 0; i--)
        printLevel(root, i);
}

bool TreeSearch(Node *root, int val)
{
    // Use any Traversal
    // Preorder Traversal
    if (root == NULL)
        return false;
    stack<Node *> STACK;
    STACK.push(root);
    while (!STACK.empty())
    {
        Node *cur = STACK.top();
        if (cur->data == val)
            return true;
        STACK.pop();
        if (cur->left)
            STACK.push(cur->left);
        if (cur->right)
            STACK.push(cur->right);
    }
    return false;
}

// Diameter of Tree
int diameter(Node *root, int &MAX)
{
    if (root)
    {
        int L = diameter(root->left, MAX), R = diameter(root->right, MAX);
        MAX = max(MAX, L + R);
        return max(L, R) + 1;
    }
    return 0;
}

int TreeDiameter(Node *root)
{
    if (root == NULL)
        return 0;
    int MAX = 0;
    diameter(root, MAX);
    return MAX;
}

// Check if Tree is height-balanced
int depth(Node *root, bool &ans)
{
    if (root == NULL)
        return 0;
    int L = depth(root->left, ans), R = depth(root->right, ans);
    if (abs(L - R) > 1)
        ans = false;
    return 1 + max(L, R);
}

bool TreeBalanced(Node *root)
{
    bool ans = true;
    depth(root, ans);
    return ans;
}

// Invert a binary tree
Node *invertTreeRecursion(Node *root)
{
    if (root == NULL)
        return root;
    Node *temp = root->left;
    root->left = invertTreeRecursion(root->right);
    root->right = invertTreeRecursion(temp);
    return root;
}

Node *invertTreeIterative(Node *root)
{
    if (root == NULL)
        return root;
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *cur = Q.front();
        Q.pop();
        Node *temp = cur->left;
        cur->left = cur->right;
        cur->right = temp;
        if (cur->left)
            Q.push(cur->left);
        if (cur->right)
            Q.push(cur->right);
    }
    return root;
}

// Check if Binary Tree is a mirror of itself
bool isMirror(Node *L, Node *R)
{
    if (L == NULL && R == NULL)
        return true;
    if (L == NULL || R == NULL)
        return false;
    return (L->data == R->data) && isMirror(L->left, R->right) && isMirror(L->right, R->left);
}
bool isSymmetricRecursion(Node *root)
{
    return isMirror(root, root);
}

bool isSymmetricIterative(Node *root)
{
    queue<Node *> Q;
    Q.push(root);
    Q.push(root);
    while (!Q.empty())
    {
        Node *L = Q.front();
        Q.pop();
        Node *R = Q.front();
        Q.pop();
        if (L == NULL && R == NULL)
            continue;
        if (L == NULL || R == NULL || L->data != R->data)
            return false;
        Q.push(L->left);
        Q.push(R->right);
        Q.push(L->right);
        Q.push(R->left);
    }
    return true;
}

int main()
{
    vector<int> nodes = {3, 9, 20, 15, 7};
    Node *root = constructBinaryTree(nodes);
    int val;
    cin >> val;
    TreeSearch(root, val) ? cout << "found" : cout << "not found";
    return 0;
}