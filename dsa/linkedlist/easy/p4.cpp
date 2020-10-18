// https://practice.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1
// Count Pairs whose sum is equal to X

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

int countPairs(struct Node* head1, struct Node* head2, int x) {
    unordered_set<int> SET;
    int count=0;
    while (head1!=NULL) {
        SET.insert(head1->data);
        head1=head1->next;
    }
    while (head2!=NULL) {
        if (SET.find(x-(head2->data)) != SET.end())
            count++;
        head2=head2->next;
    }
    return count;
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        int a[n];
        for (int i=0; i<n; i++) 
            cin>>a[i];
    }
    return 0;
}