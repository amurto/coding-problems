// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0
// The Painter's Partition Problem

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[31][51];

int MinimumTime(int *a, int k, int n) {
    if (n<0)
        return 0;
    if (DP[k][n] < 0) {
        int sum=0;
        for (int i=n; i>=0; i--) {
            sum+=a[i];
            if (DP[k][n] == -1)
                DP[k][n] = max(sum, MinimumTime(a, k-1, i-1));
            else
                DP[k][n] = min(DP[k][n], max(sum, MinimumTime(a, k-1, i-1)));
        }
    }
    return DP[k][n];
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int k, n;
        cin>>k>>n;
        int a[n], sum=0;
        for (int i=0; i<n; i++) 
            cin>>a[i];
        memset(DP, -1, sizeof(DP));
        for (int i=0; i<n; i++) {
            sum+=a[i];
            DP[1][i] = sum;
        } 
        cout<<MinimumTime(a, k, n-1)<<endl;
    }
    return 0;
}