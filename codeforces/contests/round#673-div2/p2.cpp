#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        ll T, v, cur=1, same=1, count=0;
        cin>>n>>T;

        // For each pair, p1 + p2 = T
        // Put smaller element as 1 and greater element as 0
        // If p1 and p2 are equal, use a flag and alter it everytime that element occurs
        // So, for T = 6, first 3 = 0, second 3 = 1, third 3 = 0 and so on....
        
        for (int i=0; i<n; i++) {
            cin>>v;
            if (T%2==0 && v == T/2) {
                same = same^1;
                cur=same;
            } else {
                if (v>T-v)
                    cur = 0;
                else
                    cur=1;
            }
            cout<<cur<<" ";
        }
        cout<<endl;
    }
    return 0;
}