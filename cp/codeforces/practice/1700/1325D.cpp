// https://codeforces.com/contest/1325/problem/D
// Ehab the Xorcist

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll u, v;
    cin >> u >> v;
    if (u > v || ((u & 1) != (v & 1)))
    {
        cout << "-1\n";
        return;
    }
    if (u == v)
    {
        if (u == 0)
        {
            cout << "0\n";
            return;
        }
        cout << "1\n"
             << u << "\n";
        return;
    }
    ll x = (v - u) / 2;
    vector<ll> res;
    if (u & x)
    {
        res.pb(u);
        res.pb(x);
        res.pb(x);
    }
    else
    {
        res.pb(u + x);
        res.pb(x);
    }
    cout << res.size() << "\n";
    for (ll r : res)
        cout << r << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}