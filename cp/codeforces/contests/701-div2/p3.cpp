#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll x, y, res = 0;
    cin >> x >> y;
    for (ll k = 1; min(x / k - 1, y) > k && k * k < x; k++)
        res += min(x / k - 1, y) - k;
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