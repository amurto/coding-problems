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
    Node(int val, Node *left, Node *right) : data(val), left(left), right(right) {}
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
- [Zigzag Level Order Traversal](#zigzag-level-order)
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
- [Cousins in Binary Tree](#cousins)
- [Node to Root path](#node-root-path)
- [All Nodes Distance K in Binary Tree](#nodes-distance-k)
- [Find a Corresponding Node of a Binary Tree in a Clone of That Tree](#find-clone-node)
- [Transform to Left Cloned Tree](#normal-left-cloned)
- [Transform from Left Cloned to Normal Tree](#left-cloned-normal)
- [Delete Leaves With a Given Value](#delete-target-leaves)
- [Binary Tree Tilt](#tilt)
- [Validate Binary Search Tree](#validate-bst)

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
https://leetcode.com/problems/binary-tree-inorder-traversal/
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
https://leetcode.com/problems/binary-tree-preorder-traversal/
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
https://leetcode.com/problems/binary-tree-postorder-traversal/
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
https://leetcode.com/problems/binary-tree-level-order-traversal/
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

<div id="zigzag-level-order">

## Zigzag Level Order Traversal
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
```cpp
vector<vector<int>> zigzagLevelOrder(Node *root)
{
    vector<vector<int>> zz;
    if (root == NULL)
        return zz;
    int level = 0;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        vector<int> cur;
        stack<Node *> temp;
        while (!st.empty())
        {
            Node *parent = st.top();
            st.pop();
            cur.push_back(parent->data);
            if (level)
            {
                if (parent->right)
                    temp.push(parent->right);
                if (parent->left)
                    temp.push(parent->left);
            }
            else
            {
                if (parent->left)
                    temp.push(parent->left);
                if (parent->right)
                    temp.push(parent->right);
            }
        }
        zz.push_back(cur);
        st = temp;
        level ^= 1;
    }
    return zz;
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
int TreeDiameter(Node *root, int &dia)
{
    if (root == NULL)
        return 0;
    int ht = -1;
    int sh = -1;
    for (Node *child : root->children)
    {
        int ch = TreeDiameter(child, dia);
        if (ch >= ht)
        {
            sh = ht;
            ht = ch;
        }
        else if (ch >= sh)
            sh = ch;
    }
    if (sh + ht + 2 > dia)
        dia = sh + ht + 2;
    ht += 1;
    return ht;
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
    return min({root->data, TreeMinimum(root->left), TreeMinimum(root->right)});
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

<div id="cousins">

## Cousins in Binary Tree
https://leetcode.com/problems/cousins-in-binary-tree/
```cpp
bool isCousins(Node *root, int x, int y)
{
    if (root == NULL)
        return false;
    int depthX = 0, depthY = 0, parentX = -1, parentY = -1;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    // BFS 
    // Every iteration is removing nodes of the same level
    // If both are found on same level, check for similarity between parents
    // If only one of them is found on the same level, they are not cousins
    while (!q.empty())
    {
        int len = q.size();
        int p1 = -1, p2 = -1;
        while (len-- > 0)
        {
            if (q.front().first->data == x)
                p1 = q.front().second;
            if (q.front().first->data == y)
                p2 = q.front().second;
            Node *parent = q.front().first;
            q.pop();
            if (parent->left)
                q.push({parent->left, parent->data});
            if (parent->right)
                q.push({parent->right, parent->data});
        }
        if (p1 >= 0 && p2 >= 0)
            if (p1 != p2)
                return true;
            else
                return false;
        if (p1 >= 0 || p2 >= 0)
            return false;
    }
    return false;
}
```
</div>

<div id="node-root-path">

## Node to Root path
```cpp
bool PathFinder(Node *cur, int val, vector<int> &path)
{
    if (cur == NULL)
        return false;
    if (cur->data == val)
    {
        path.push_back(cur->data);
        return true;
    }
    if (cur->left && PathFinder(cur->left, val, path))
    {
        path.push_back(cur->data);
        return true;
    }
    if (cur->right && PathFinder(cur->right, val, path))
    {
        path.push_back(cur->data);
        return true;
    }
    return false;
}

vector<int> NodeToRootPath(Node *root, int val)
{
    vector<int> path;
    PathFinder(root, val, path);
    return path;
}
```
</div>

<div id="nodes-distance-k">

## All Nodes Distance K in Binary Tree
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
```cpp
// Get path from target to root
// All parent nodes
bool getPath(Node *cur, Node *target, vector<Node *> &path)
{
    if (cur == NULL)
        return false;
    if (cur == target)
    {
        path.push_back(target);
        return true;
    }
    if ((cur->left && getPath(cur->left, target, path)) || (cur->right && (getPath(cur->right, target, path))))
    {
        path.push_back(cur);
        return true;
    }
    return false;
}

// Find all nodes at a distance of K
void dfs(Node *cur, int K, vector<int> &res)
{
    if (cur == NULL)
        return;
    if (K == 0)
        res.push_back(cur->data);
    else
    {
        dfs(cur->left, K - 1, res);
        dfs(cur->right, K - 1, res);
    }
}

vector<int> distanceK(Node *root, Node *target, int K)
{
    vector<Node *> path;
    getPath(root, target, path);
    vector<int> res;
    for (int i = 0; i < path.size() && K >= 0; i++, K--)
        if (K == 0)
            res.push_back(path[i]->data);
        else if (i == 0)
            dfs(path[i], K, res);
        else if (path[i]->left && path[i]->left == path[i - 1])
            dfs(path[i]->right, K - 1, res);
        else
            dfs(path[i]->left, K - 1, res);
    return res;
}
```
</div>

<div id="find-clone-node">

## Find a Corresponding Node of a Binary Tree in a Clone of That Tree
https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
```cpp
Node *getTargetCopy(Node *original, Node *cloned, Node *target)
{
    if (original == NULL || cloned == NULL || target == NULL)
        return NULL;
    // BFS with two queues
    queue<Node *> q1, q2;
    q1.push(original);
    q2.push(cloned);
    while (!q1.empty())
    {
        Node *cur1 = q1.front();
        q1.pop();
        Node *cur2 = q2.front();
        q2.pop();
        if (cur1 == target)
            return cur2;
        if (cur1->right)
            q1.push(cur1->right);
        if (cur2->right)
            q2.push(cur2->right);
        if (cur1->left)
            q1.push(cur1->left);
        if (cur2->left)
            q2.push(cur2->left);
    }
    return NULL;
}
```
</div>

<div id="normal-left-cloned">

## Transform to Left Cloned Tree
```cpp
Node *createLeftCloneTree(Node *cur)
{
    if (cur == NULL)
        return NULL;
    Node *LC = createLeftCloneTree(cur->left);
    Node *RC = createLeftCloneTree(cur->right);
    Node *clone = new Node(cur->data, cur->left, NULL);
    cur->left = clone;
    cur->right = RC;
    return cur;
}
```
</div>

<div id="left-cloned-normal">

## Transform from Left Cloned to Normal Tree
```cpp
Node *createNormalTree(Node *cur)
{
    if (cur == NULL)
        return NULL;
    if (cur->left) cur->left = cur->left->left;
    cur->left = createNormalTree(cur->left);
    cur->right = createNormalTree(cur->right);
    return cur;
}

```
</div>

<div id="delete-target-leaves">

## Delete Leaves With a Given Value
https://leetcode.com/problems/delete-leaves-with-a-given-value/
```cpp
Node *removeLeafNodes(Node *root, int target)
{
    if (root == NULL)
        return NULL;
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if (root->left == NULL && root->right == NULL && root->data == target)
        root = NULL;
    return root;
}
```
</div>

<div id="tilt">

## Binary Tree Tilt
```cpp
int subtreeSum(Node *cur, int &tilt)
{
    if (cur == NULL)
        return 0;
    int L = subtreeSum(cur->left, tilt), R = subtreeSum(cur->right, tilt);
    tilt += abs(L - R);
    return cur->data + L + R;
}

int findTilt(Node *root)
{
    int tilt = 0;
    subtreeSum(root, tilt);
    return tilt;
}
```
</div>

<div id="validate-bst">

## Validate Binary Search Tree
https://leetcode.com/problems/validate-binary-search-tree/
```cpp
bool isValidBST(Node *root)
{
    stack<Node *> st;
    Node *cur = root, *prev = NULL;
    while (cur || !st.empty())
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        if (prev && prev->data >= st.top()->data)
            return false;
        prev = st.top();
        st.pop();
        if (prev->right)
            cur = prev->right;
    }
    return true;
}
```
</div>