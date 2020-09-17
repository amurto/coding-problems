#include<bits/stdc++.h>
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

void insert(Node** root, int v)
{
    Node* temp = new Node(v);
    Node* ptr;
    temp->next = NULL;
    if (*root == NULL)
        *root = temp;
    else
    {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

Node *arrayToList(int n) 
{ 
    Node *root = NULL; 
    int v;
    for (int i = 0; i < n; i++) {
        cin>>v;
        insert(&root, v); 
    }
    return root; 
} 

int listLength(Node *head) {
    if (head==NULL)
        return 0;
    return 1+listLength(head->next);
}

int maxPalindrome(Node *head)
{
    int n=listLength(head);
    int P[n][n], MAX=1;
    Node *ptr1=head, *ptr2=head;
    for (int gap=1; gap<n; gap++) {
        ptr1=head, ptr2=head;
        for (int i=0; i<gap; i++)
            ptr2=ptr2->next;
        for (int i=0; i<n-gap;i++) {
            int j=i+gap;
            if (ptr1->data==ptr2->data && (gap<=2 || P[i+1][j-1] == 1)) {
                P[i][j]=1;
                MAX=max(MAX, gap+1);
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    return MAX;
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        int a[n];
        Node* root = arrayToList(n);
        cout<<maxPalindrome(root)<<endl;
    }
    return 0;
}