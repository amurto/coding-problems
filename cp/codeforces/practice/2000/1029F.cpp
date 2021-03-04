// https://codeforces.com/contest/1029/problem/F
// Multicolored Markers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void fac(ll a, vector<ll> &x, vector<ll> &y)
{
    for (ll i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            x.pb(i);
            y.pb(a / i);
        }
    }
}

ll solve()
{
    ll a, b;
    cin >> a >> b;
    vector<ll> x1, y1, x2, y2;
    fac(min(a, b), x1, y1);
    fac(max(a, b), x2, y2);
    a += b;
    ll res = 2 * a + 2;
    for (ll i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            int idx = upper_bound(x1.begin(), x1.end(), i) - x1.begin();
            idx--;
            if (idx >= 0 && x1[idx] <= i && y1[idx] <= (a / i))
                res = min(res, 2ll * (i + a / i));
            idx = upper_bound(x2.begin(), x2.end(), i) - x2.begin();
            idx--;
            if (idx >= 0 && x2[idx] <= i && y2[idx] <= (a / i))
                res = min(res, 2ll * (i + a / i));
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}