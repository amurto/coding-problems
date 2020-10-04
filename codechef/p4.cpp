#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve() {
    int n, x, p, k;
    cin>>n>>x>>p>>k;
    p--;
    // Contains exactly p elements less than X

    // Check if X is present in array
    int present = 0;

    // Count number of elements less than X and occurrences of X
    int arr[n], less=0, occur=0;

    for (int i=0; i<n; i++) {
        cin>>arr[i];
        if (arr[i] == x) {
            present=1;
            occur++;
        }

        if (arr[i]<x)
            less++;
    }

    // pth smallest element is X already
    if (less==p) {
        if (k<p)
            return -1;
        else 
            return !present;
    } else if (less < p) {
        // less < p
        // increase smaller elements
        // k>=p 
        if (k>=p) {
            return p - less + !present;
        }
        return -1;
    } else {
        // less > p
        // decrease smaller elements 
        // less - p
        if (k<p) {
            return less - p + !present;
        }
        return -1;
    }

    
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t-->0) {
        cout<<solve()<<"\n";
    }
    return 0;
}