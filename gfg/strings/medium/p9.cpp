// Longest Palindromic Subsequence
// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int LPS(char str[], int n) {
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<n; i++) 
        dp[i][i]=1;
    
    for (int gap=1; gap<n; gap++) {
        for (int i=0; i<n-gap; i++) {
            int j=i+gap;
            if (str[i] == str[j]) {
                if (gap==1)
                    dp[i][j]=2;
                else
                    dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        string s;
        cin >> s;
        int n = s.length();
        char str[n];
        for (int i = 0; i < n; i++)
            str[i] = s[i];
        cout<<LPS(str, n)<<endl;
    }
    return 0;
}