// https://practice.geeksforgeeks.org/problems/decode-the-pattern/0
// Decode the pattern

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    vector<vector<int>> pattern = {{1}};
    int p=0;
    while (p<20) {
        vector<int> cur;
        int i=0, j=0;
        while (i<pattern[p].size()) {
            while (j<pattern[p].size() && pattern[p][j] == pattern[p][i])
                j++;
            cur.pb(j-i);
            cur.pb(pattern[p][i]);  
            i=j;
        }
        pattern.pb(cur);
        p++;
    }
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        for (int v: pattern[n-1])
            cout<<v;
        cout<<endl;
    }
    return 0;
}