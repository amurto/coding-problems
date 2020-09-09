#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        string str;
        cin>>str;
        int n=str.length(), itr=0, i=0, d=0, add=0;
        int count[10];
        memset(count, 0, sizeof(count));
        vector<int> ans;
        while (itr<n) {
            while (str[i] == 'D') {
                d++;
                i++;
            }
            for(int j=d; j>0; j--)
                ans.pb(add+d);
            add+=d;
            d=0;

            
        }
    }
    return 0;
}