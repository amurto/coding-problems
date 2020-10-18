// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
// 0 - 1 Knapsack Problem

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[1001][1001];
int maxCap(int *v, int *wt, int w, int n) {
    if (n<0 || w==0)
        return 0;
    if (DP[w][n] < 0)
        if (wt[n] > w)  
            DP[w][n] = maxCap(v, wt, w, n-1);
        else
            DP[w][n] = max(v[n] + maxCap(v, wt, w-wt[n], n-1), maxCap(v, wt, w, n-1));
    return DP[w][n];
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n, w;
        cin>>n>>w;
        int wt[n], v[n], DP[w+1][n];
        for (int i=0; i<n; i++) 
            cin>>v[i];
        for (int i=0; i<n; i++) 
            cin>>wt[i];
        memset(DP, -1, sizeof(DP));
        cout<<maxCap(v, wt, w, n-1)<<endl;
    }
    return 0;
}