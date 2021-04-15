// https://codeforces.com/contest/1348/problem/D
// Phoenix and Science

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll n, sum = 1, p = 1, m = 1;
    cin >> n;
    vector<ll> split, add, cnt;
    while (sum < n)
    {
        split.pb(m);
        m <<= 1;
        add.pb(m);
        sum += m;
    }
    int sz = split.size();
    if (sum > n)
    {
        sum -= add[sz - 1];
        ll p = split[sz - 1];
        if (n - sum >= p)
            split[sz - 1] = (n - sum) - p;
        else
        {
            sum -= add[sz - 2];
            ll req = n - sum, c = split[sz - 2];
            ll a1 = req / 2, a2 = req / 2;
            if (req & 1)
                a2++;
            split[sz - 2] = a1 - c;
            c += split[sz - 2];
            split[sz - 1] = a2 - c;
        }
    }
    cout << sz << "\n";
    for (ll x : split)
        cout << x << " ";
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