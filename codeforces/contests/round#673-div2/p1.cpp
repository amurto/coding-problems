#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int M[10001];

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n, k;
        cin>>n>>k;
        int a[n], MIN=INT_MAX, count=0;
        for (int i=0; i<n; i++) {
            cin>>a[i];
            MIN=min(MIN, a[i]);
        }
        for (int v: a)
            count = count + (k-v)/MIN;
        count = count - (k-MIN)/ MIN;
        cout<<count<<endl;
    }
    return 0;
}