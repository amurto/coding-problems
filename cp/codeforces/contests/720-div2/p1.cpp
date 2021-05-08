#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll a, b;
    cin >> a >> b;
    if (b == 1)
    {
        cout << "NO\n";
        return;
    }
    if (b == 2)
        b *= 3;
    vector<ll> nums = {a, a * (b - 1), a * b};
    cout << "YES\n";
    for (ll e : nums)
        cout << e << " ";
    cout << "\n";
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