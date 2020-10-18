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

* Insertion into BST
* Deletion from BST
* Level order print
* Traversal(inorder , preorder and postorder)
* Searching a value in BST
* Check if is BST or not
* Find inorder successor and inorder predecessor
* Print all root node to leaf node paths
* Find min and max value in BST