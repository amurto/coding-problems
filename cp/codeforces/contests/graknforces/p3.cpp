#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        ll len;
        cin>>n>>len;
        n+=2;
        ll flags[n];
        flags[0]=0;
        flags[n-1] = len;
        for (int i=1; i<n-1; i++) 
            cin>>flags[i];
        ll speed=1;
        double timeA[n], timeB[n];
        timeA[0] = 0;
        timeB[n-1] = 0;
        for (int i=1; i<n; i++) {
            timeA[i] = timeA[i-1] + (flags[i]-flags[i-1]) / speed;
            timeB[n-i-1] = timeB[n-i] + (flags[n-i] - flags[n-i-1])/speed;
            speed++;
        }
        int idx=0;
        while (idx<n-1 && timeA[idx+1] < timeB[idx+1])
            idx++;
        cout<<n-idx-1<<endl;
        double ans = (flags[idx+1] - flags[idx])/(idx+n-idx);
        cout<<flags[idx+1] <<" "<< flags[idx]<<" "<<(idx+n-idx)<<endl;
        ans+=timeA[idx];
        cout<<"Ans:"<<ans<<endl;
        for (int i=0; i<n; i++) 
            cout<<flags[i]<<" ";
    }
    return 0;
}