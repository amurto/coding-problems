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
        sort(arr.begin(), arr.end());
        int g = 1;
        for (int i=0; i<n; i++) 
            if (i + 1 >= arr[i])
                g = i + 2;
        cout << g << "\n";
    }
    return 0;
}