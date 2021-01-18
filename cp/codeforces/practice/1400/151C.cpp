// https://codeforces.com/contest/151/problem/C
// Win or Freeze

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll q, x;
    cin >> q;
    x = q;
    vector<ll> f;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
            {
                f.pb(i);
                x /= i;
            }
        }
    }
    if (x > 1 && x != q)
        f.pb(x);
    if (f.empty() || f.size() >= 3)
    {
        cout << "1\n";
        f.empty() ? cout << "0\n" : cout << f[0] * f[1] << "\n";
        return;
    }
    cout << "2\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}