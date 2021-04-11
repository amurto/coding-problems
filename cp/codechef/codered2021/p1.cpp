#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    ll x1, y1, x2, y2, t;
    cin >> x1 >> y1 >> x2 >> y2 >> t;
    ll mdis = abs(y2 - y1) + abs(x2 - x1), dgdis = max(abs(x2 - x1), abs(y2 - y1));
    return (dgdis <= t && t - dgdis != 1) || (mdis <= t && t - mdis != 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}