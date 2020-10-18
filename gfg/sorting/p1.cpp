// Merge two sorted arrays

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
}

int main() {
    int m, n;
    cin>>m>>n;
    vector<int> nums1(m), nums2(n);
    for (int i=0; i<m; i++)
        cin>>nums1[i];
    for (int i=0; i<n; i++)
        cin>>nums2[i];
    merge(nums1, m, nums2, n);
    
    return 0;
}