#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n, x;
        cin>>n>>x;
        int a[n], same=0, avg=0;;
        for (int i=0; i<n; i++) 
            cin>>a[i];
        for (int v: a) {
            if (v == x)
                same++;
            if (v>x)
                avg = avg + abs(v-x);
            else
                avg = avg - abs(v-x);
        }
        if (same == n)
            cout<<0<<endl;
        else if (avg == 0 || same>0)
            cout<<1<<endl;
        else    
            cout<<2<<endl;
    }
    return 0;
}