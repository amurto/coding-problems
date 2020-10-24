#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int toInt(string str)
{
    int num;
    stringstream ss(str);
    ss >> num;
    return num;
}

vector<int> LineToArray(char delimeter, string unwanted, int n)
{
    vector<int> nodes;
    string num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num == "n")
            nodes.push_back(-1);
        else
            nodes.push_back(toInt(num));
    }
    return nodes;
}

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

Node *CT(vector<int> &nodes, int &idx, int &n)
{
    if (idx == n || nodes[idx] == -1)
        return NULL;
    Node *cur = new Node(nodes[idx]);
    cur->left = CT(nodes, ++idx, n);
    cur->right = CT(nodes, ++idx, n);
    return cur;
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

int TreeMinimum(Node *root)
{
    if (root == NULL)
        return INT_MAX;
    return min({root->data, TreeMinimum(root->left), TreeMinimum(root->right)});
}

int TreeMaximum(Node *root)
{
    if (root == NULL)
        return -1;
    return max({root->data, TreeMaximum(root->left), TreeMaximum(root->right)});
}

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

Node *getTargetCopy(Node *original, Node *cloned, Node *target)
{
    if (original == NULL || cloned == NULL || target == NULL)
        return NULL;
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

void display(Node *node)
{
    if (node == NULL)
        return;
    string str = "";
    str += node->left == NULL ? "." : to_string(node->left->data) + "";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right == NULL ? "." : to_string(node->right->data) + "";
    cout << str << "\n";
    display(node->left);
    display(node->right);
}

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

Node *createNormalTree(Node *cur)
{
    if (cur == NULL)
        return NULL;
    if (cur->left)
        cur->left = cur->left->left;
    cur->left = createNormalTree(cur->left);
    cur->right = createNormalTree(cur->right);
    return cur;
}

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

class Subtree
{
public:
    int size, MAX, MIN, ans;
    bool isBST;
    Subtree() {}
    Subtree(int size, int MAX, int MIN, int ans, bool isBST) : size(size), MAX(MAX), MIN(MIN), ans(ans), isBST(isBST) {}
};

Subtree checkBST(Node *cur)
{
    if (cur == NULL)
        return Subtree(0, INT_MIN, INT_MAX, 0, true);
    if (cur->left == NULL && cur->right == NULL)
        return Subtree(1, cur->data, cur->data, 1, true);
    Subtree L = checkBST(cur->left);
    Subtree R = checkBST(cur->right);
    Subtree res;
    res.size = 1 + L.size + R.size;
    res.MIN = min({cur->data, L.MIN, R.MIN});
    res.MAX = max({cur->data, L.MAX, R.MAX});
    if (L.isBST && R.isBST && cur->data > L.MAX && cur->data < R.MIN)
        res.isBST = true;
    else
        res.isBST = false;
    if (res.isBST)
        res.ans = res.size;
    else
        res.ans = max(L.ans, R.ans);
    return res;
}
int largestBst(Node *root)
{
    Subtree res = checkBST(root);
    return res.ans;
}

// Iterative
// Post order traversal
// Break loop when both are found, that is, found = 2
// Keep popping stack until such a parent is found where the state was 0
Node *lowestCommonAncestorIterative(Node *root, Node *p, Node *q)
{
    stack<pair<Node *, int>> st;
    Node *cur = root;
    int found = 0;
    while (cur || !st.empty())
    {
        while (cur)
        {
            st.push({cur, found});
            if (cur == p || cur == q)
                found++;
            cur = cur->left;
        }
        if (found == 2)
            break;
        cur = st.top().first;
        if (cur->right)
            cur = cur->right;
        else
        {
            st.pop();
            while (!st.empty() && st.top().first->right == cur)
            {
                cur = st.top().first;
                st.pop();
            }
            cur = NULL;
        }
    }
    while (!st.empty() && st.top().second > 0)
        st.pop();
    if (st.empty())
        return NULL;
    return st.top().first;
}

// Recursive
bool findLCA(Node *cur, Node *p, Node *q, Node *&lca)
{
    if (cur == NULL)
        return false;
    int found = (cur == p || cur == q) + findLCA(cur->left, p, q, lca) + findLCA(cur->right, p, q, lca);
    if (found >= 2)
        lca = cur;
    return (found > 0);
}
Node *lowestCommonAncestorRecursive(Node *root, Node *p, Node *q)
{
    Node *lca = NULL;
    findLCA(root, p, q, lca);
    return lca;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nodes = LineToArray(' ', "n", n);
    int idx = 0;
    Node *root = CT(nodes, idx, n);
    return 0;
}