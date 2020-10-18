// https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1
// Delete without head pointer

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void deleteNode(Node *node)
{
    *node = *(node->next);
}

int main()
{
    return 0;
}