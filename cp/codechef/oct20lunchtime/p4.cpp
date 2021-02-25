// SSO

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

        ll ans = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            ans ^= arr[i];
            ans ^= sum;
        }
        cout << ans << "\n";
    }
    return 0;
}