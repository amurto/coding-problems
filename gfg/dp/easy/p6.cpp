// https://practice.geeksforgeeks.org/problems/reach-a-given-score/0
// Reach a given score

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int Combinations(int n) {
    int DP[n+1];
    memset(DP, 0, sizeof(DP));
    DP[0] = 1;
    for (int i=3; i<=n; i++)
        DP[i]+=DP[i-3];
    for (int i=5; i<=n; i++)
        DP[i]+=DP[i-5];
    for (int i=10; i<=n; i++)
        DP[i]+=DP[i-10];
    return DP[n];
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        cout<<Combinations(n)<<endl;
    }
    return 0;
}