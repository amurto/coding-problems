#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n, k;
        cin>>n;
        int a[n];
        unordered_set<int> SET;
        for (int i=0; i<n; i++) {
            cin>>a[i];
            SET.insert(a[i]);
        }
        int dup = SET.size();   
    }
    return 0;
}