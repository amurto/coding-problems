#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for (int i=0; i<n; i++) 
            cin>>arr[i];

        vector<int> b(n);
        for (int i=0; i<n; i+=2) {
            b[i] = -arr[i+1];
            b[i+1] = arr[i];
        }
        for (int val: b)
            cout << val << " ";
        cout << "\n";
    }
    return 0;
}