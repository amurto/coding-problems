// https://practice.geeksforgeeks.org/problems/longest-prefix-suffix/0
// Longest Prefix Suffix

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n, m, ans=0;;
        string s;
        cin>>s;
        n=s.length();
        for (int i=1; i<n; i++) {
            if (s[0] == s[i]) {
                if (s.substr(0, n-i) == s.substr(i, n-i)) {
                    ans=n-i;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}