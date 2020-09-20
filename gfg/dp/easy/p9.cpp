// https://practice.geeksforgeeks.org/problems/maximum-sum-problem/0
// Maximum sum Problem
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[100001];
int MSP(int n) {
    if (DP[n] < 0) 
        DP[n] = max(n, MSP(n/2) + MSP(n/3) + MSP(n/4));
    return DP[n];
}

int main() {
    int t;
    cin>>t;
    memset(DP, -1, sizeof(DP));
    DP[0] = 0;
    while (t-->0) {
        int n;
        cin>>n;
        cout<<MSP(n)<<endl;
    }
    return 0;
}