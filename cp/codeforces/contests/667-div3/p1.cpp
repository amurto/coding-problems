#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        long long a, b;
        cin>>a>>b;
        long long d = abs(a-b);
        d = d/10 + (d%10 == 0 ? 0 : 1);
        cout<<d<<endl;
    }
    return 0;
}