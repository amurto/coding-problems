#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll n, k, sum = 0;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    ll low = 0, high = 1e18, res = 1e18;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (sum / (n + mid) <= k)
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}