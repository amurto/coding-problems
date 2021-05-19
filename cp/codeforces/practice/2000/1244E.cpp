// https://codeforces.com/contest/1244/problem/E
// Minimizing Difference

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll lv = arr[0], l_id = 0, rv = arr[n - 1], r_id = n - 1;
    while (k > 0 && l_id < r_id)
    {
        ll ld = l_id + 1, rd = n - r_id;
        if (ld <= rd)
        {
            ll t = arr[l_id + 1];
            ll d = abs(t - lv);
            if (d * ld <= k)
            {
                k -= d * ld;
                lv = t;
                l_id++;
            }
            else
            {
                lv += k / ld;
                k = 0;
            }
        }
        else
        {
            ll t = arr[r_id - 1];
            ll d = abs(t - rv);
            if (d * rd <= k)
            {
                k -= d * rd;
                rv = t;
                r_id--;
            }
            else
            {
                rv -= k / rd;
                k = 0;
            }
        }
    }
    return rv - lv;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}