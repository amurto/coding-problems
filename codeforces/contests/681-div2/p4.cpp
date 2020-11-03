#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve(vector<int> &arr, vector<int> &dec, vector<int> &inc, int n)
{
    dec[0] = arr[0];
    inc[0] = 0;
    for (int i=1; i<n;i++) {
        dec[i] = min(dec[i-1], arr[i] - inc[i-1]);
        inc[i] = arr[i] - dec[i];
        if (inc[i] < inc[i-1] || dec[i] < 0)
            return "NO";
    }
    return "YES";
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
        vector<int> arr(n), a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << solve(arr, a, b, n) << "\n";
    }
    return 0;
}

/*
1
6
11 11 12 14 11 12
*/