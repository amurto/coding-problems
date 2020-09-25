#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int MAS(int *DP, int *a, int n) {
    if (n<1)
        return a[0];
    if (DP[n] < 0) {
        DP[n] = max(a[n], MAS(DP, a, n-1));
        for (int i=n-1; i>=0; i--) {
            DP[n] = max(DP[n], a[n] - a[i] + MAS(DP, a, i-1));
        }
    }
    return DP[n];
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n, q;
        cin>>n>>q;
        int a[n];
        for (int i=0; i<n; i++) 
            cin>>a[i];

        int DP[n];
        memset(DP, -1, sizeof(DP));
        DP[0] = a[0];
        cout<<MAS(DP, a, n-1)<<endl;
    }
    return 0;
}