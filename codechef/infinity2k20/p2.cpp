// SOLDVAL

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

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
        vector<ll> arr(n+1), L(n+1), R(n+1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        L[1] = arr[1];
        R[n] = arr[n];
        for (int i=2; i<=n; i++)
            L[i] = min(L[i-1] + 1, arr[i]);
        for (int i=n-1; i>0; i--)
            R[i] = min(R[i+1] + 1, arr[i]);
        for (int i=1; i<=n; i++)
            cout << min(L[i], R[i]) << " ";
        cout << "\n";
    }
    return 0;
}