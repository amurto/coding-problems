// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
// Maximum sum increasing subsequence

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int calSum(int *arr, int *DP, int n, int cur) {
    if (DP[cur] < 0) {
        DP[cur] = arr[cur];
        for (int i=cur+1; i<n; i++)
            if (arr[i] > arr[cur])
                DP[cur] = max(DP[cur], arr[cur] + calSum(arr, DP, n, i));
    }
    return DP[cur];
}

int maxSumIS(int arr[], int n)  
{  
    int DP[n];
    memset(DP, -1, sizeof(DP));
    int MAX=0;
    for (int i=n-1; i>=0; i--) 
        MAX = max(MAX, calSum(arr, DP, n, i));
    return MAX;
} 

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++) 
            cin>>arr[i];
        cout<<maxSumIS(arr, n)<<endl;
    }
    return 0;
}