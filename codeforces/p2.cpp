#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        ll a[n], ans=0;
        int memo[70];
        memset(memo, 0, sizeof(memo));
        for (int i=0; i<n; i++) {
            cin>>a[i];
            memo[(int)(log2(a[i]))]++;
        }
        for (int v: memo)
            ans = ans + v*(v-1)/2;
        cout<<ans<<endl;
    }
    return 0;
}
