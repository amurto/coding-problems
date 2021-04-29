#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    ll r, b, d;
    cin >> r >> b >> d;
    if (r < b)
        swap(r, b);
    if (d == 0)
        return r == b;
    return ((r - b + d - 1) / d) <= b;
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