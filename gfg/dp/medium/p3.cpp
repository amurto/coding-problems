// https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1
// Count ways to N'th Stair(Order does not matter)

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

long long countWays(int n){
    ll DP[n+1];
    memset(DP, 0, sizeof(DP));
    DP[0] = 1;
    for (int i=1; i<=n; i++) 
        DP[i]+=DP[i-1];
    for (int i=2; i<=n; i++) 
        DP[i]+=DP[i-2];
    return DP[n];
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        cout<<countWays(n)<<endl;
    }
    return 0;
}