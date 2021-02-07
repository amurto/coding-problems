// https://codeforces.com/contest/617/problem/C
// Watering Flowers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll sq(int e)
{
    return e * 1ll * e;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x1, y1, x2, y2, x, y;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<pair<ll, ll>> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        d[i].first = sq(x1 - x) + sq(y1 - y);
        d[i].second = sq(x2 - x) + sq(y2 - y);
    }
    sort(d.begin(), d.end());
    vector<ll> suf(n + 1);
    for (int i = n - 1; i >= 0; i--)
        suf[i] = max(suf[i + 1], d[i].second);
    ll res = suf[0];
    for (int i = 0; i < n; i++)
        res = min(res, d[i].first + suf[i + 1]);
    cout << res << "\n";
    return 0;
}