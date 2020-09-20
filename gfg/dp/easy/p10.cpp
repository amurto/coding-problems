// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0
// Shortest Common Supersequence

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[101][101];

int LCS(string &str1, string &str2, int m, int n) {
    if (m<0 || n<0)
        return 0;
    if (DP[m][n]<0)
        if (str1[m] == str2[n])
            DP[m][n] = 1 + LCS(str1, str2, m-1, n-1);
        else
            DP[m][n] = max(LCS(str1, str2, m-1, n), LCS(str1, str2, m, n-1));
    return DP[m][n];
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        string str1, str2;
        cin>>str1>>str2;
        int m = str1.length(), n = str2.length();
        memset(DP, -1, sizeof(DP));
        int ans = m + n - LCS(str1, str2, m-1, n-1);
        cout<<ans<<endl;
    }
    return 0;
}