#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll sq_root(ll x)
{
    ll l = 0, r = 2e9 + 1;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    if (l * l == x)
        return l;
    return 0;
}

ll nc2(ll n)
{
    return (n * 1ll * (n - 1)) / 2;
}

void solve()
{
    ll x, y;
    cin >> x >> y;
    ll n = sq_root(x + y);
    if (n == 0)
    {
        cout << "NO\n";
        return;
    }
    if (n == 2)
    {
        if (x == 2 && y == 2)
        {
            cout << "YES\n";
            cout << 2 << "\n";
            cout << "1 2"
                 << "\n";
        }
        else
            cout << "NO\n";
        return;
    }
    ll reqx = (x - n) / 2, reqy = y / 2 - n + 1;
    if (reqy == 0 && reqx == nc2(n - 1))
    {
        cout << "YES\n";
        cout << n << "\n";
        for (ll j = 2; j <= n; j++)
            cout << 1 << " " << j << "\n";
        return;
    }
    for (ll i = 1; i * i <= reqy; i++)
    {
        if (reqy % i == 0)
        {
            ll d = reqy / i;
            if ((nc2(i) + nc2(d) + i + d) == reqx)
            {
                cout << "YES\n";
                cout << n << "\n";
                cout << "1 2"
                     << "\n";
                ll e = 3;
                for (ll j = 0; j < i; j++, e++)
                    cout << 1 << " " << e << "\n";
                for (ll j = 0; j < d; j++, e++)
                    cout << 2 << " " << e << "\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}