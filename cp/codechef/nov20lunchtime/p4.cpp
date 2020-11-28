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
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        ll res = arr[0], h = arr[0];
        int L = 1, R = n - 1;
        while (L < R)
        {
            if (arr[L] > arr[R])
            {
                h += arr[L];
                L++;
            }
            else
            {
                h += arr[R];
                R--;
            }
            res = min(res, h);
        }
        cout << res << "\n";
    }
    return 0;
}