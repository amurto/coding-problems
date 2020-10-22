#include <bits/stdc++.h>
using namespace std;

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

int TreeSize(Node *root)
{
    if (root == NULL)
        return 0;
    int size = 1;
    for (Node *temp : root->children)
        size += TreeSize(temp);
    return size;
}

int TreeHeight(Node *root)
{
    if (root == NULL)
        return 0;
    int height = 0;
    for (Node *temp : root->children)
        height = max(height, TreeHeight(temp));
    return height + 1;
}

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

int TreeMaximum(Node *root)
{
    if (root == NULL)
        return 0;
    int MAX = root->val;
    for (Node *temp : root->children)
        MAX = max(MAX, TreeMaximum(temp));
    return MAX;
}

int TreeMinimum(Node *root)
{
    if (root == NULL)
        return 0;
    int MIN = root->val;
    for (Node *temp : root->children)
        MIN = min(MIN, TreeMinimum(temp));
    return MIN;
}

// https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// N-ary Tree Level Order Traversal
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

bool PathFinder(Node *cur, int val, vector<int> &path)
{
    if (cur == NULL)
        return false;
    if (cur->val == val)
    {
        path.push_back(cur->val);
        return true;
    }
    for (Node *child : cur->children)
    {
        if (PathFinder(child, val, path))
        {
            path.push_back(cur->val);
            return true;
        }
    }
    return false;
}

vector<int> NodeToRootPath(Node *root, int val)
{
    vector<int> path;
    PathFinder(root, val, path);
    return path;
}

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

int main()
{
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++)
        cin >> nodes[i];
    Node *root = constructTree(nodes);
    int lca = -1, v1, v2;
    cin >> v1 >> v2;
    LCA(root, v1, v2, lca);
    cout << lca << "\n";
    return 0;
}