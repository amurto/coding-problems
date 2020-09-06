// Convert Ternary Expression to Binary Tree
// https://practice.geeksforgeeks.org/problems/convert-ternary-expression-to-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct Node
{
    char data;
    Node *left, *right;
};

Node *convertExpression(string str,int i)
{
    Node *root = new Node();
    root->data=str[i];
    if (str.length() == 1) {
        root->left=NULL;
        root->right=NULL;
    } else {
        int j=2, c=0;
        while (str[j] != ':' || c!=0) {
            if (str[j]=='?')
                c++;
            else if (str[j] == ':')
                c--;
            j++;
        }
        root->left=convertExpression(str.substr(2, j-2), 0);
        root->right=convertExpression(str.substr(j+1, str.length()-j-1), 0);
    }
    return root;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin >> s;
        convertExpression(s, 0);
    }
    return 0;
}