#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DominantPiranha(vector<ll> &arr, int n)
{
    ll MAX=0;
    for (int i=0; i<n; i++)
        MAX = max(MAX, arr[i]);
    for (int i=0; i<n; i++) {
        if (arr[i] == MAX) {
            if (i> 0 && arr[i-1] < MAX)
                return i+1;
            else if (i<n-1 && arr[i+1] < MAX)
                return i+1;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << DominantPiranha(arr, n) << "\n";
    }
    return 0;
}