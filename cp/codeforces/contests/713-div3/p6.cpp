#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    ll c, res = 1e18, d = 0, cur = 0;
    cin >> n >> c;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
        cin >> b[i];

    for (int i = 0; i < n - 1; i++)
    {
        if (cur >= c)
        {
            res = min(res, d);
            break;
        }
        res = min(res, d + (c - cur + a[i] - 1) / a[i]);
        ll t = (b[i] - cur + a[i] - 1) / a[i];
        cur += t * a[i];
        d += t + 1;
        cur -= b[i];
    }
    res = min(res, d + (c - cur + a[n - 1] - 1) / a[n - 1]);
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