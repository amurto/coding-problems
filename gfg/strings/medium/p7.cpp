// https://practice.geeksforgeeks.org/problems/longest-even-length-substring/0
// Longest Even Length Substring

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
        int a[n], left=0, right=0, lsum=0, rsum=0, m=0;
        for (int i=0; i<n; i++) 
            a[i]=s[i]-48;

        for (int i=1; i<n; i++) {
            lsum=0;
            rsum=0;
            left=i-1;
            right=i;
            while (left>=0 && right<n) {
                lsum+=a[left];
                rsum+=a[right];
                if (lsum==rsum)
                    m=max(m, right-left+1);
                left--;
                right++;
            }
        }
        cout<<m<<endl;
    }
    return 0;
}