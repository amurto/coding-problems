// Factorials of large numbers
// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Manual multiplication
void mul(vector<int> &ans, int v) {
    int p, carry=0;
    for (int i=0; i<ans.size(); i++) {
        p = ans[i]*v + carry;
        carry = p/10;
        p%=10;
        ans[i] = p;
    }
    while (carry>0) {
        ans.pb(carry%10);
        carry/=10;
    }
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        vector<int> ans;
        ans.pb(1);
        for (int i=2; i<=n; i++)
            mul(ans, i);
        for (int i=ans.size()- 1; i>=0; i--)
            cout<<ans[i]<<"";
        cout<<endl;
    }
    return 0;
}