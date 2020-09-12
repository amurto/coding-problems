// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
// Kadane's Algorithm
// Maximum sub-array

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        int a[n];
        for (int i=0; i<n; i++) 
            cin>>a[i];
        int sum=0, maximum=INT_MIN;
        for (int i=0; i<n; i++) {
            sum = max(sum+a[i], a[i]);
            maximum=max(sum, maximum);
        }
        cout<<maximum<<endl;
    }
    return 0;
}