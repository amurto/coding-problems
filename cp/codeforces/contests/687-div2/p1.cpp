#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll n, m, r, c;
        cin >> n >> m >> r >> c;
        ll m1 = abs(r - 1) + abs(c - 1);
        ll m2 = abs(r - 1) + abs(c - m);
        ll m3 = abs(r - n) + abs(c - 1);
        ll m4 = abs(r - n) + abs(c - m);
        ll ans = max({m1, m2, m3, m4});
        cout << ans << "\n";
    }
    return 0;
}