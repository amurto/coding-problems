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
        ll MAX = 0, MIN = INT_MAX;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            MAX = max(MAX, arr[i]);
            MIN = min(MIN, arr[i]);
        }
        sort(arr.begin(), arr.end());
        if (MIN == 0)
        {
            ll ans = 0;
            for (int i = 1; i < n; i++)
                ans += MAX - arr[i];
            cout << ans << "\n";
        }
        else
        {
            cout << "tbd\n";
        }
    }
    return 0;
}