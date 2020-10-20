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
        int zero = 0, i=0, j=n-1;
        while (arr[i] == 0)
            i++;
        while (arr[j] == 0)
            j--;
        while (i<j) {
            while (i < j && arr[i] == 1)
                i++;
            while (i < j && arr[i] == 0) {
                zero++;
                i++;
            }
        }
        cout << zero << "\n";
    }
    return 0;
}