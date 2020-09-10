// https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0
// Count subsequences of type a^i b^j c^k
// Combinatorics

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
        for (int i=0; i<n; i++) 
            str[i] =s[i];
        int aw=0,bw=0,cw=0;
        // aw = Number of ways to select atleast 1 a from number of a's so far
        // bw = aw + Number of ways to select atleast 1 b from number of b's so far
        // cw = bw + Number of ways to select atleast 1 c from number of b's so far
        for (int i=0; i<n; i++) {
            if (str[i] == 'a')
                aw=1+2*aw;
            else if (str[i] == 'b')
                bw=aw+2*bw;
            else
                cw=bw+2*cw;
        }
        cout<<cw<<endl;
    }
    return 0;
}