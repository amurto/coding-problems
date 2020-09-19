// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
// Longest Repeating Subsequence

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        string str;
        cin>>n>>str;
        int DP[n][n];
        memset(DP, 0, sizeof(DP));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<i; j++) {
                if (str[i-1] == str[j-1]) {
                    DP[i][j] = 1;
                }
                DP[i][j] += DP[i-1][j-1];
            }
        }
        cout<<DP[n][n]<<endl;
    }
    return 0;
}