// https://practice.geeksforgeeks.org/problems/distinct-palindromic-substrings/0/
// Distinct palindromic substrings

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        string s;
        cin>>s;
        int n=s.length();
        char str[n];
        set<string> hashset;
        for (int i=0; i<n; i++) 
            str[i] =s[i];

        int P[n][n];
        memset(P, 0, sizeof(P));
        for (int gap=0; gap<n; gap++) {
            for (int i=0; i<n-gap; i++) {
                int j= i+gap;
                if (str[i] == str[j] && (gap<=1 || P[i+1][j-1])) {
                    P[i][j]=1;
                    hashset.insert(s.substr(i, gap+1));
                }
            }
        }
        cout<<hashset.size()<<endl;
    }
    return 0;
}