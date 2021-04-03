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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int mn = 1e9 + 5;
        for (int i = 1; i < n; i++)
            mn = min(mn, arr[i] - arr[i - 1]);
        cout << mn << "\n";
    }
    return 0;
}