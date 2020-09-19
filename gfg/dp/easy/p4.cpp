// https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right/0
// Count all possible paths from top left to bottom right

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[1000][1000], MOD = 1000000007;
int countPaths(int m, int n) {
    if (DP[m][n] < 0)
        if (m==0 || n==0)
            DP[m][n]=1;
        else
            DP[m][n] = (countPaths(m, n-1) + countPaths(m-1, n))%MOD;
    return DP[m][n];
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int m, n;
        cin>>m>>n;
        memset(DP, -1, sizeof(DP));
        cout<<countPaths(m-1, n-1)<<endl;
    }
    return 0;
}