#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll lxm = 0, rxm = 0, lym = 0, rym = 0;
    if (n & 1)
        lxm = rxm = x[n / 2];
    else
    {
        lxm = x[n / 2 - 1];
        rxm = x[n / 2];
    }
    if (n & 1)
        lym = rym = y[n / 2];
    else
    {
        lym = y[n / 2 - 1];
        rym = y[n / 2];
    }
    ll res = (rxm - lxm + 1) * (rym - lym + 1);
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