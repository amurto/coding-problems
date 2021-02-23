#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll p, a, b, c;
    cin >> p >> a >> b >> c;
    ll a1 = (p + a - 1) / a, b1 = (p + b - 1) / b, c1 = (p + c - 1) / c;
    a1 *= a;
    b1 *= b;
    c1 *= c;
    return min({a1 - p, b1 - p, c1 - p});
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