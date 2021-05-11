#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll h, c, t;
    cin >> h >> c >> t;
    vector<pair<ll, ll>> seq;
    seq.pb({h + c, 2});
    ll low = 0, high = 1e6, res = 1e6;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll tmp = h + mid * (h + c);
        tmp /= (2 * mid + 1);
        if (tmp < t)
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    seq.pb({h + res * (h + c), 2 * res + 1});
    res--;
    seq.pb({h + res * (h + c), 2 * res + 1});
    vector<pair<double, ll>> arr;
    for (pair<ll, ll> s : seq)
        arr.pb({abs(1.0 * t - 1.0 * s.first / s.second), s.second});
    sort(arr.begin(), arr.end());
    return arr[0].second;
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