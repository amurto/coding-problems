// https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring/0
// Length of the longest substring

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        string str;
        cin>>str;
        int h[256], start=0, m=0;
        memset(h, -1, sizeof(h));
        for (int i=0; i<str.length();i++) {
            start=max(start, h[str[i]] + 1);
            m = max(m, i-start+1);
            h[str[i]]=i;
        }
        cout<<m<<endl;
    }
    return 0;
}