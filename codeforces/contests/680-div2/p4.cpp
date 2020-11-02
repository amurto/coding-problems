#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
const int MOD = 998244353;

int partition(vector<int> arr, int n) {
    vector<int> a, b;
    for (int i=0; i<n; i++)
        a.pb(arr[i]);
    for (int i=n; i<2*n; i++)
        b.pb(arr[i]);
    sort(a.begin() ,a.end());
    sort(b.begin(), b.end(), greater<int>());
    int ans =0;
    for (int i=0; i<n; i++)
        ans = ans + abs(a[i] - b[i]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) 
        cin>>arr[i];
    n/=2;
    cout << partition(arr, n) << "\n";
    sort(arr.begin(), arr.end());
    cout << partition(arr, n) << "\n";
    return 0;
}