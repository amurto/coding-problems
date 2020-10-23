#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    Node(int val, Node *left, Node *right) : data(val), left(left), right(right) {}
};

vector<int> LineToArray(char delimeter, string unwanted)
{
    vector<int> nodes;
    string S, T;
    // Empty character
    getline(cin, S);
    getline(cin, S);
    stringstream X(S);
    while (getline(X, T, delimeter))
        if (T == unwanted)
            nodes.push_back(-1);
        else
            nodes.push_back(stoi(T));
    return nodes;
}

Node *CT(vector<int> &nodes, int &idx, int &n)
{
    if (idx == n || nodes[idx] == -1)
        return NULL;
    Node *cur = new Node(nodes[idx]);
    cur->left = CT(nodes, ++idx, n);
    cur->right = CT(nodes, ++idx, n);
    return cur;
}

int TreeHeight(Node *root)
{
    if (root)
        return 1 + max(TreeHeight(root->left), TreeHeight(root->right));
    return 0;
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
    {
        printLevel(root, i);
        cout << "\n";
    }
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

int main()
{
    int n;
    cin >> n;
    vector<int> nodes = LineToArray(' ', "n");
    int idx = 0;
    Node *root = CT(nodes, idx, n);
    return 0;
}


// vector<int> nodes = {3, 9, 20, 15, 7};
// Node *root = constructBinaryTree(nodes);
// int val;
// cin >> val;
// TreeSearch(root, val) ? cout << "found" : cout << "not found";