#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll a, b;
    cin >> a >> b;
    if (a < b)
        swap(a, b);
    if (a == b)
    {
        cout << "0 0\n";
        return;
    }
    if (b == 0)
    {
        cout << a << " " << b << "\n";
        return;
    }
    ll d = a - b;
    ll t1 = b / d;
    ll m = d * t1;
    ll mn = min(abs(b - m), abs(b - m - d));
    cout << d << " " << mn << "\n";
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