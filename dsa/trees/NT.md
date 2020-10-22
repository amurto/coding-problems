# N-ary Tree
https://www.geeksforgeeks.org/generic-treesn-array-trees/
## Structure

```cpp
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
```

## Table of Contents

- [Construction](#construction)
- [N-ary Tree Level Order Traversal](#level-order)
- [N-ary Tree Preorder Traversal](#preorder)
- [N-ary Tree Postorder Traversal](#postorder)
- [Number of nodes in N-ary Tree](#size)
- [Searching of Value](#search)
- [Height of N-ary Tree](#height)
- [Diameter of Tree](#diameter)
- [Find minimum value in N-ary Tree](#minimum)
- [Find maximum value in N-ary Tree](#maximum)
- [Node to Root path](#node-root-path)
- [Lowest Common Ancestor in N-ary Tree](#lca)

<div id="construction">

## Construction

```cpp
Node *constructTree(vector<int> &nodes)
{
    if (nodes.size() == 0)
        return NULL;
    stack<Node *> STACK;
    Node *root = new Node(nodes[0]);
    STACK.push(root);
    for (int i = 1; i < nodes.size(); i++)
    {
        if (nodes[i] == -1)
            STACK.pop();
        else
        {
            Node *node = new Node(nodes[i]);
            if (!STACK.empty())
                STACK.top()->children.push_back(node);
            STACK.push(node);
        }
    }
    return root;
}
```

</div>

<div id="level-order">

## N-ary Tree Level Order Traversal

https://leetcode.com/problems/n-ary-tree-level-order-traversal/

```cpp
vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> trav;
    if (root == NULL)
        return trav;
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        vector<int> curNodes;
        int count = Q.size();
        while (count-- > 0)
        {
            Node *node = Q.front();
            Q.pop();
            curNodes.push_back(node->val);
            for (Node *temp : node->children)
                Q.push(temp);
        }
        trav.push_back(curNodes);
    }
    return trav;
}
```

</div>

<div id="">

## N-ary Tree Preorder Traversal

https://leetcode.com/problems/n-ary-tree-preorder-traversal/

```cpp
// Recursive
void preTraverse(Node *cur, vector<int> &pre)
{
    if (cur == NULL)
        return;
    pre.push_back(cur->val);
    for (Node *child : cur->children)
        preTraverse(child, pre);
}
vector<int> preorderRecursive(Node *root)
{
    vector<int> pre;
    preTraverse(root, pre);
    return pre;
}

// Iterative
vector<int> preorderIterative(Node *root)
{
    vector<int> pre;
    stack<pair<Node *, int>> STACK;
    Node *cur = root;
    while (cur || !STACK.empty())
    {
        while (cur)
        {
            pre.push_back(cur->val);
            STACK.push({cur, 0});
            if (cur->children.empty())
                cur = NULL;
            else
                cur = cur->children[0];
        }
        int idx = STACK.top().second;
        STACK.pop();
        if (!STACK.empty() && idx < STACK.top().first->children.size() - 1)
        {
            STACK.push({STACK.top().first->children[idx + 1], idx + 1});
            pre.push_back(STACK.top().first->val);
            if (!STACK.top().first->children.empty())
                cur = STACK.top().first->children[0];
        }
    }
    return pre;
}
```

</div>

<div id="postorder">

## N-ary Tree Postorder Traversal

https://leetcode.com/problems/n-ary-tree-postorder-traversal/

```cpp
// Recursive
void postTraverse(Node *cur, vector<int> &post)
{
    if (cur == NULL)
        return;
    for (Node *child : cur->children)
        postTraverse(child, post);
    post.push_back(cur->val);
}
vector<int> postorderRecursive(Node *root)
{
    vector<int> post;
    postTraverse(root, post);
    return post;
}

// Iterative
vector<int> postorderIterative(Node *root)
{
    vector<int> post;
    stack<pair<Node *, int>> STACK;
    Node *cur = root;
    while (cur || !STACK.empty())
    {
        while (cur)
        {
            STACK.push({cur, 0});
            if (cur->children.empty())
                cur = NULL;
            else
                cur = cur->children[0];
        }
        int idx = STACK.top().second;
        post.push_back(STACK.top().first->val);
        STACK.pop();
        if (!STACK.empty() && idx < STACK.top().first->children.size() - 1)
        {
            STACK.push({STACK.top().first->children[idx + 1], idx + 1});
            if (!STACK.top().first->children.empty())
                cur = STACK.top().first->children[0];
        }
    }
    return post;
}
```

</div>

<div id="size">

## Number of nodes in N-ary Tree

```cpp
int TreeSize(Node *root)
{
    if (root == NULL)
        return 0;
    int size = 1;
    for (Node *temp : root->children)
        size += TreeSize(temp);
    return size;
}
```
</div>

<div id="search">

## Searching 
```cpp
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
        if (cur->val == val)
            return true;
        STACK.pop();
        for (Node *child : cur->children)
            STACK.push(child);
    }
    return false;
}
```
</div>

<div id="height">

## Height of N-ary Tree

```cpp
int TreeHeight(Node *root)
{
    if (root == NULL)
        return 0;
    int height = 0;
    for (Node *temp : root->children)
        height = max(height, TreeHeight(temp));
    return height + 1;
}
```

</div>

<div id="diameter">

## Diameter of N-ary Tree

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

<div id="minimum">

## Find minimum value in N-ary Tree

```cpp
int TreeMinimum(Node *root)
{
    if (root == NULL)
        return 0;
    int MIN = root->val;
    for (Node *temp : root->children)
        MIN = min(MIN, TreeMinimum(temp));
    return MIN;
}
```

</div>

<div id="maximum">

## Find maximum value in N-ary Tree

```cpp
int TreeMaximum(Node *root)
{
    if (root == NULL)
        return 0;
    int MAX = root->val;
    for (Node *temp : root->children)
        MAX = max(MAX, TreeMaximum(temp));
    return MAX;
}
```

</div>

<div id="node-root-path">

## Node to Root path
```cpp
bool PathFinder(Node *cur, int val, vector<int> &path) {
    if (cur == NULL)
        return false;
    if (cur -> val == val) {
        path.push_back(cur->val);
        return true;
    }
    for (Node *child : cur->children) {
        if (PathFinder(child, val, path)) {
            path.push_back(cur->val);
            return true;
        }
    }
    return false;
}

vector<int> NodeToRootPath(Node *root, int val) {
    vector<int> path;
    PathFinder(root, val, path);
    return path;
}
```
</div>

<div id="lca">

## Lowest Common Ancestor in N-ary Tree
```cpp
bool LCA(Node *cur, int v1, int v2, int &lca)
{
    if (cur == NULL)
        return false;
    int found = 0;
    for (Node *child : cur->children)
        if (LCA(child, v1, v2, lca))
            found++;
    if (cur->val == v1 || cur->val == v2)
        found++;
    if (found >= 2)
        lca = cur->val;
    return (found > 0);
}
```
</div>