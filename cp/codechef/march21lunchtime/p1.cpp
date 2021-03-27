#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll a, y, x;
    cin >> a >> y >> x;
    ll sum = a * x + 1;
    sum -= max(0ll, (a - y) * x);
    if (a >= y)
        sum--;
    return sum;
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