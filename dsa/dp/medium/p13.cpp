// https://practice.geeksforgeeks.org/problems/total-decoding-messages/0
// Total Decoding Messages

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int valid(int v) {
    if (v>0 && v<=26)
        return 1;
    return 0;
}

int TDM(int *a, int *DP, int n) {
    if (DP[n]<0) 
        DP[n] = ((a[n-1] > 0 && valid(a[n-1]*10 + a[n])) ? TDM(a, DP, n-2) : 0) + (valid(a[n]) ? TDM(a, DP, n-1) : 0);
    return DP[n];
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        string str;
        cin>>str;
        int a[n], DP[n];
        for (int i=0; i<n; i++)
            a[i] = str[i]-48;
        memset(DP, -1, sizeof(DP));
        DP[0] = valid(a[0]);
        if (n>1)
            DP[1] = (valid(a[0]) && valid(a[1])) + (a[0] > 0 && valid(a[0]*10 + a[1]));
        cout<<TDM(a, DP, n-1)<<endl;
    }
    return 0;
}