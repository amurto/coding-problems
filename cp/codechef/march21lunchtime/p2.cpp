#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll run(ll x, ll m)
{
    if (x >= m)
        return m;
    m -= x;
    return x + m / 2;
}

bool solve()
{
    ll x, r, m;
    cin >> x >> r >> m;
    r *= 60;
    m *= 60;
    return run(x, m) >= r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}