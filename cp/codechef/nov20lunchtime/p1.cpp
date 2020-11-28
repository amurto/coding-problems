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
            cin >> arr[i].second;
        for (int i = 0; i < n; i++)
            cin >> arr[i].first;
        sort(arr.begin(), arr.end());
        ll dis = 0, p = 0;
        int i = 0;
        while (dis < n && i < n)
        {
            if (dis + arr[i].second <= n)
            {
                dis += arr[i].second;
                p += arr[i].first * arr[i].second;
            }
            else
            {
                p += arr[i].first * (n - dis);
                dis = n;
            }
            i++;
        }
        cout << p << "\n";
    }
    return 0;
}