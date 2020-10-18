// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game/0
// Optimal Strategy For A Game

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
int DP[101][101];

int MM(int* a, int n, int L, int R) {
    if (n<=0)
        return 0;
    if (DP[L][R] < 0)
        if (n==2)
            DP[L][R] = max(a[L], a[R]);
        else 
            DP[L][R] = max(a[L] + min(MM(a, n-2, L+2, R), MM(a, n-2, L+1, R-1)), 
            a[R] + min(MM(a, n-2, L, R-2), MM(a, n-2, L+1, R-1)));
    return DP[L][R];
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
        memset(DP, -1, sizeof(DP));
        cout<<MM(a, n, 0, n-1)<<endl;
    }
    return 0;
}