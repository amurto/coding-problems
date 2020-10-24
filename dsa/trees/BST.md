# Binary Search Tree
https://www.geeksforgeeks.org/binary-search-tree-data-structure/

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

- [Insertion into BST](#insertion)
- [Deletion from BST](#deletion)
- [Searching a value in BST](#search)
- [Find min and max value in BST](#min-max)
- [Convert BST to Greater Tree](#bst-gt)
- [Nodes in Range BST](#range-print)
- [Range Sum of BST](#range-sum)
- [Target Sum Pair in BST / Two Sum IV](#tsp-bst)
- [Lowest Common Ancestor of a Binary Search Tree](#lca-bst)

<div id="insertion">

## Insertion into BST
```cpp
// Insertion iteratively
Node *insertNodeIteration(Node *root, int val)
{
    Node *node = new Node(val), *cur = root, *prev = NULL;
    while (cur)
    {
        prev = cur;
        if (val <= cur->data)
            cur = cur->left;
        else if (val > cur->data)
            cur = cur->right;
    }
    if (prev == NULL)
        cur = node;
    else if (val <= prev->data)
        prev->left = node;
    else
        prev->right = node;
    return root;
}

// Iteration recursively
Node *insertNodeRecursion(Node *cur, int val)
{
    if (cur == NULL)
        return new Node(val);
    if (val <= cur->data)
        cur->left = insertNodeRecursion(cur->left, val);
    else
        cur->right = insertNodeRecursion(cur->right, val);
    return cur;
}
```
</div>

<div id="deletion">

## Deletion from BST
https://leetcode.com/problems/delete-node-in-a-bst/
```cpp
Node *deleteSuccessor(Node *del, int &dkey)
{
    // Traverse to maximum value of current subtree
    // Find inorder successor, store its value and delete the node
    if (del->right == NULL)
    {
        dkey = del->data;
        return del->left;
    }
    del->right = deleteSuccessor(del->right, dkey);
    return del;
}

Node *removeNode(Node *del)
{
    // If key is not found, return NULL
    if (del == NULL)
        return NULL;
    if (del->left == NULL)
        return del->right;
    if (del->right == NULL)
        return del->left;
    // key has two children
    // Find inorder successor
    int dkey = 0;
    del->left = deleteSuccessor(del->left, dkey);
    del->data = dkey;
    return del;
}

Node *deleteNode(Node *root, int key)
{
    Node *cur = root, *prev = NULL;
    // Traverse to key
    while (cur && cur->data != key)
    {
        prev = cur;
        if (key < cur->data)
            cur = cur->left;
        else if (key > cur->data)
            cur = cur->right;
    }
    // key is root of tree
    if (prev == NULL)
        root = removeNode(cur);
    // key is left child of parent
    else if (prev->left == cur)
        prev->left = removeNode(cur);
    // key is right child of parent
    else
        prev->right = removeNode(cur);
    return root;
}
```
</div>

<div id="search">

## Searching a value in BST
```cpp
bool search(Node *cur, int x)
{
    if (cur == NULL)
        return false;
    if (x < cur->data)
        return search(cur->left, x);
    else if (x > cur->data)
        return search(cur->right, x);
    return true;
}
```
</div>

<div id="min-max">

## Find min and max value in BST
```cpp
int BSTminimum(Node *cur)
{
    if (cur->left)
        return BSTminimum(cur->left);
    return cur->data;
}

int BSTmaximum(Node *cur)
{
    if (cur->right)
        return BSTmaximum(cur->right);
    return cur->data;
}
```
</div>

<div id="bst-gt">

## Convert BST to Greater Tree
https://leetcode.com/problems/convert-bst-to-greater-tree/
```cpp
int BSTtoGT(Node *cur, int sum) {
    if (cur==NULL)
        return sum;
    cur->data += BSTtoGT(cur->right, sum);
    return BSTtoGT(cur->left, cur->data);
}

Node* convertBST(Node* root) {
    BSTtoGT(root, 0);
    return root;
}
```
</div>

<div id="range-nodes">

## Nodes in Range BST
```cpp
void rangeInorder(Node *cur, int L, int R)
{
    if (cur == NULL)
        return;
    if (cur->data < L)
        rangeInorder(cur->right, L, R);
    else if (cur->data > R)
        rangeInorder(cur->left, L, R);
    else
    {
        rangeInorder(cur->left, L, R);
        cout << cur->data << "\n";
        rangeInorder(cur->right, L, R);
    }
}
```
</div>

<div id="range-sum">

## Range Sum of BST
https://leetcode.com/problems/range-sum-of-bst/
```cpp
int rangeSumBST(Node *cur, int L, int R)
{
    if (cur == NULL)
        return 0;
    if (cur->data < L)
        return rangeSumBST(cur->right, L, R);
    else if (cur->data > R)
        return rangeSumBST(cur->left, L, R);
    return rangeSumBST(cur->left, L, R) + cur->data + rangeSumBST(cur->right, L, R);
}
```
</div>

<div id="tsp-bst">

## Target Sum Pair in BST
```cpp
// Moves the value of current node in increasing or decreasing order in BST
int movePointer(Node *&cur, stack<Node *> &st, int op, int dir)
{
    if (!cur && st.empty())
        return -1;
    while (cur)
    {
        st.push(cur);
        cur = dir == 0 ? cur->left : cur->right;
    }
    cur = st.top();
    op = cur->data;
    st.pop();
    cur = dir == 0 ? cur->right : cur->left;
    return op;
}

vector<pair<int, int>> TSP(Node *root, int target)
{
    vector<pair<int, int>> pairs;
    stack<Node *> st1, st2;
    Node *cur1 = root, *cur2 = root;
    int L = movePointer(cur1, st1, L, 0), R = movePointer(cur2, st2, R, 1);
    while (L < R)
    {
        if (L + R < target)
            L = movePointer(cur1, st1, L, 0);
        else if (L + R > target)
            R = movePointer(cur2, st2, R, 1);
        else
        {
            pairs.push_back({L, R});
            L = movePointer(cur1, st1, L, 0);
            R = movePointer(cur2, st2, R, 1);
        }
    }
    return pairs;
}
```

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
```cpp
bool findTarget(Node *root, int k)
{
    stack<Node *> st1, st2;
    Node *cur1 = root, *cur2 = root;
    int L = movePointer(cur1, st1, L, 0), R = movePointer(cur2, st2, R, 1);
    while (L < R)
        if (L + R < k)
            L = movePointer(cur1, st1, L, 0);
        else if (L + R > k)
            R = movePointer(cur2, st2, R, 1);
        else
            return true;
    return false;
}
```
</div>

<div id="lca-bst">

## Lowest Common Ancestor of a Binary Search Tree
```cpp
// Iterative
Node *lowestCommonAncestorIterative(Node *root, Node *p, Node *q)
{
    Node *cur = root;
    while (cur)
        if (cur->data > p->data && cur->data > q->data)
            cur = cur->left;
        else if (cur->data < p->data && cur->data < q->data)
            cur = cur->right;
        else
            return cur;
    return cur;
}

// Recursive
Node *lowestCommonAncestorRecursive(Node *root, Node *p, Node *q)
{
    if (root == NULL)
        return NULL;
    if (root->data > p->data && root->data > q->data)
        return lowestCommonAncestorRecursive(root->left, p, q);
    else if (root->data < p->data && root->data < q->data)
        return lowestCommonAncestorRecursive(root->right, p, q);
    return root;
}
```
</div>