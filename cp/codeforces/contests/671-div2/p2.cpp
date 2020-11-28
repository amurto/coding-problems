#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll cellsUsed(ll n) {
    return (n*n)/2 + (n+1)/2;
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        ll n, ans=0, i=1, p=1;
        cin>>n;
        while (n-cellsUsed(i)>=0) {
            n-=cellsUsed(i);
            i = i + pow(2, p);
            p++;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}