#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        ll n, x, y;
        cin>>n>>x>>y;
        ll d = y-x, m = n-1;
        while (d%m > 0)
            m--;
        ll step = d/m;
        vector<ll> a;
        for (ll i=x; i<=y; i+=step) 
            a.push_back(i);
        ll rem = n-a.size();
        x-=step;
        while (x>0 && rem>0) {
            a.push_back(x);
            rem--;
            x-=step;
        }
        while (rem>0) {
            y+=step;
            a.push_back(y);
            rem--;
        }
        for (int i=0; i<a.size(); i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}