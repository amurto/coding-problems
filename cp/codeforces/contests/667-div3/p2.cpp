#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void decreaseA(ll &a, ll &x, ll &n) {
    if (n<=0 || a<=x)
        return;
    ll m = min(n, a-x);
    n=n-m;
    a=a-m;
}

void decreaseB(ll &b, ll &y, ll &n) {
    if (n<=0 || b<=y)
        return;
    ll m = min(n, b-y);
    n=n-m;
    b=b-m;
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        ll a, b, x, y, n;
        cin>>a>>b>>x>>y>>n;
        if (a==b) {
            if (x<y) {
                decreaseA(a, x, n);
                decreaseB(b, y, n);
            }
            else {
                decreaseB(b, y, n);
                decreaseA(a, x, n);
            }
        } else if (max(a-n, x)<max(b-n, y)) {
            decreaseA(a, x, n);
            decreaseB(b, y, n);
        } else {
            decreaseB(b, y, n);
            decreaseA(a, x, n);
        }
        cout<<a*b<<endl;
    }
    return 0;
}