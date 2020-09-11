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
        int a[n], left=0, right=0, sum=0;
        unordered_map<int, int> dict;
        for (int i=0; i<n; i++) 
            a[i]=s[i]-48;

        for (int i=0; i<n; i++) {
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}