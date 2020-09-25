#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve(ll *a, int n) {
    for (int i=0; i<n-1; i++) 
        if (a[i] > a[i+1])
            return "NO";
    return "YES";
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n, ans=0;
        cin>>n;
        ll a[n];
        for (int i=0; i<n; i++) 
            cin>>a[i];
        cout<<solve(a, n)<<endl;
    }
    return 0;
}