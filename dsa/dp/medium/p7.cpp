// https://practice.geeksforgeeks.org/problems/coin-change2448/1
// Coin Change

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll count(int *S, int m, int n) {
    ll DP[n+1];
    memset(DP, 0, sizeof(DP));
    DP[0] = 1;
    for (int i=0; i<m; i++)
        for (int j=S[i]; j<=n; j++) 
            DP[j] += DP[j-S[i]];
    return DP[n];
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n, m;
        cin>>n>>m;
        int S[n];
        for (int i=0; i<m; i++) 
            cin>>S[i];
        cout<<count(S, m, n)<<endl;
    }
    return 0;
}