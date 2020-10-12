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
- [Deletion of Node]()
- [InorderTraversal (Recursive and Iterative)]()
- [Preorder Traversal (Recursive and Iterative)]()
- [Postorder Traversal (Recursive and Iterative)]()
- [Level Order Traversal](#level-order)
- [Reverse Level Order traversal]()
- [Searching of Value]()
- [Height of Tree]()
- [Diameter of Tree]()
- [Mirror of Tree]()
- [Check Tree is balanced or not]()
- [Find minimum value in Tree]()
- [Find maximum value in Tree]()

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
```

</div>

<div id="level-order">

## Level Order Traversal

```cpp
void LevelOrderTraversal(Node *root) {
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
```

</div>
