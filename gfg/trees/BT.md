# Binary Tree

https://www.geeksforgeeks.org/binary-tree-data-structure/

## Structure

```cpp
struct Node {
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    Node(int val, Node *left, Node *right) : data(val),left(left), right(right) {}
};
```

## Table of Contents

- [Properties](#properties)
- [Insertion of Node](#insertion)
- [Deletion of Node](#deletion)
- [InorderTraversal (Recursive and Iterative)](#inorder)
- [Preorder Traversal (Recursive and Iterative)](#preorder)
- [Postorder Traversal (Recursive and Iterative)](#postorder)
- [Level Order Traversal](#level-order)
- [Reverse Level Order traversal](#reverse-level-order)
- [Searching of Value](#search)
- [Height of Tree](#height)
- [Number of nodes in Tree](#size)
- [Sum of nodes in Tree](#sum)
- [Diameter of Tree](#diameter)
- [Invert a Binary Tree](#invert)
- [Mirror of Tree](#mirror)
- [Check Tree is balanced or not](#balanced)
- [Find minimum value in Tree](#minimum)
- [Find maximum value in Tree](#maximum)

<div id="properties">

## Properties

- The maximum number of nodes at level 'i' of a binary tree is 2^i. Level of root is 0.
- Maximum number of nodes in a binary tree of height 'h' is 2^h – 1.
- In a Binary Tree with N nodes, minimum possible height or minimum number of levels is Log2(N+1).
- A Binary Tree with L leaves has at least Log2L + 1 levels.
- In Binary tree where every node has 0 or 2 children, number of leaf nodes is always one more than nodes with two children.

```
L = T + 1
Where L = Number of leaf nodes
      T = Number of internal nodes with two children
```

- Enumeration of Trees. Check [Nth Catalan Numbers](https://www.geeksforgeeks.org/program-nth-catalan-number/).

```
For n  = 1, there is only one tree
   o

For n  = 2, there are two trees
   o      o
  /        \
 o          o

For n  = 3, there are five trees
    o      o           o         o      o
   /        \         /  \      /         \
  o          o       o    o     o          o
 /            \                  \        /
o              o                  o      o

Number of Labeled Tees = (Number of unlabeled trees) * n!
                       = [(2n)! / (n+1)!n!]  × n!
```

</div>

<div id="insertion">

## Insertion of Node

```cpp
Node *insertNode(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    // Level Order Traversal to first empty node
    // Tree should be Balanced
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

Node *constructBinaryTree(vector<int> &nodes) {
    if (nodes.size()==0)
        return NULL;
    Node *root = new Node(nodes[0]);
    for (int i=1; i<nodes.size();i++)
        root = insertNode(root, nodes[i]);
    return root;
}

// Construct Tree from given Preorder Traversal
Node* CT(vector<int> &nodes, int &idx, int &n) {
    if (idx==n || nodes[idx] == -1)
        return NULL;
    Node *cur = new Node(nodes[idx]);
    cur->left = CT(nodes, ++idx, n);
    cur->right = CT(nodes, ++idx, n);
    return cur;
}
```

</div>

<div id="deletion">

## Deletion of Node

```cpp
void deleteNode(Node *root, int val)
{
    if (root == NULL)
        return;
    // Use pair to store both lastnode and its parent
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
```

</div>

<div id="inorder">

## Inorder Traversal

```cpp
void InorderTraversalRecursion(Node *root)
{
    if (root == NULL)
        return;
    InorderTraversalRecursion(root->left);
    cout << root->data << " ";
    InorderTraversalRecursion(root->right);
}

void InorderTraversalStack(Node *root)
{
    // DFS with Stack
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
```

</div>

<div id="preorder">

## Preorder Traversal

```cpp
void PreorderTraversalRecursion(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreorderTraversalRecursion(root->left);
    PreorderTraversalRecursion(root->right);
}

void PreorderTraversalStack(Node *root)
{
    // DFS with Stack
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
```
</div>

<div id="postorder">

## Postorder Traversal
```cpp
void PostorderTraversalRecursion(Node *root)
{
    if (root == NULL)
        return;
    PostorderTraversalRecursion(root->left);
    PostorderTraversalRecursion(root->right);
    cout << root->data << " ";
}

void PostorderTraversalStack(Node *root)
{
    // DFS with Stack
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
```
</div>

<div id="level-order">

## Level Order Traversal

```cpp
// BFS with Queue
void LevelOrderTraversal(Node *root) {
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

// Recursion
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
```
</div>

<div id="reverse-level-order">

## Reverse Level Order Traversal

```cpp
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
void ReverseLevelOrderTraversalRecursion(Node *root)
{
    if (root == NULL)
        return;
    for (int i = TreeHeight(root)-1; i >=0; i--)
        printLevel(root, i);
}
```

</div>

<div id="search">

## Searching 
```cpp
bool TreeSearch(Node *root, int val) {
    // Use any Traversal
    // Preorder Traversal
    if (root==NULL)
        return false;
    stack<Node *> STACK;
    STACK.push(root);
    while (!STACK.empty()) {
        Node *cur = STACK.top();
        if (cur -> data == val)
            return true;
        STACK.pop();
        if (cur->left) STACK.push(cur->left);
        if (cur->right) STACK.push(cur->right);
    }
    return false;
}
```
</div>

<div id="height">

## Height of Tree
```cpp
int TreeHeight(Node *root) {
    if (root) 
        return 1 + max(TreeHeight(root->left), TreeHeight(root->right));
    return 0;
}
```
</div>

<div id="size">

## Size of Tree (Number of nodes)
```cpp
int TreeSize(Node *root) {
    if (root) 
        return 1 + TreeSize(root->left) + TreeSize(root->right);
    return 0;
}
```
</div>

<div id="sum">

## Sum of nodes in Tree
```cpp
int TreeSum(Node *root) {
    if (root) 
        return root->data + TreeSum(root->left) + TreeSum(root->right);
    return 0;
}
```
</div>

<div id="diameter">

## Diameter of Tree
```cpp
int diameter(Node *root, int &MAX) {
    if (root) {
        int L = diameter(root->left, MAX), R= diameter(root->right, MAX);
        MAX = max(MAX, L+R);
        return max(L,R) + 1;
    }
    return 0;
}

int TreeDiameter(Node* root) {
    if (root==NULL)
        return 0;
    int MAX=0;
    diameter(root, MAX);
    return MAX;
}
```
</div>

<div id="invert">

## Invert a Binary Tree
```cpp
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
```
</div>

<div id="mirror">

## Check if Binary Tree is mirror of itself

```cpp
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

bool isSymmetricIterative(TreeNode* root) {
    queue<TreeNode *> Q;
    Q.push(root);
    Q.push(root);
    while (!Q.empty()) {
        TreeNode *L = Q.front();
        Q.pop();
        TreeNode *R = Q.front();
        Q.pop();
        if (L==NULL && R==NULL) continue;
        if (L==NULL || R==NULL || L->val != R->val) return false;
        Q.push(L->left);
        Q.push(R->right);
        Q.push(L->right);
        Q.push(R->left);
    }
    return true;
}
```
</div>

<div id="balanced">

## Check if Tree is height balanced

```cpp
int depth(Node *root, bool &ans) {
    if (root==NULL)
        return 0;
    int L = depth(root->left, ans), R=depth(root->right, ans);
    if (abs(L-R) > 1)
        ans=false;
    return 1 + max(L,R);
}

bool TreeBalanced(Node* root) {
    bool ans=true;
    depth(root, ans);
    return ans;
}
```
</div>

<div id="minimum">

## Find minimum value in Tree
```cpp
int TreeMinimum(Node *root)
{
    if (root == NULL)
        return INT_MAX;
    return min({root->data, TreeMaximum(root->left), TreeMaximum(root->right)});
}
```
</div>

<div id="maximum">

## Find maximum value in Tree
```cpp
int TreeMaximum(Node *root)
{
    if (root == NULL)
        return -1;
    return max({root->data, TreeMaximum(root->left), TreeMaximum(root->right)});
}
```
</div>