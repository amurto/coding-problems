#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve(int n, int m) {
    int res = (m/2)*n;
    if (m&1)
        res+=(n+1)/2;
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t-->0) {
        int n, m;
        cin>>n >> m;
        cout << solve(n, m) << "\n";
    }
    return 0;
}