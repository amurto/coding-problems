#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll nc2(ll n)
{
    return (n * (n - 1)) / 2;
}

ll solve()
{
    ll n, x, t;
    cin >> n >> x >> t;
    ll d = t / x;
    if (n - d < 0)
        return nc2(n);
    return d * max(0ll, n - d) + nc2(d);
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