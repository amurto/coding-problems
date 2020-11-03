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
        vector<pair<ll, ll>> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i].first;
        for (int i = 0; i < n; i++)
            cin >> arr[i].second;
        sort(arr.begin(), arr.end(), greater<pair<ll, ll>>());
        ll prefix = 0, res = arr[0].first;
        for (int i = 0; i < n; i++)
        {
            res = min(res, max(arr[i].first, prefix));
            prefix += arr[i].second;
        }
        res = min(res, prefix);
        cout << res << "\n";
    }
    return 0;
}