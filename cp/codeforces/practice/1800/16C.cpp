// https://codeforces.com/contest/16/problem/C
// Monitor

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll g = __gcd(x, y);
    x /= g;
    y /= g;
    ll t = min(a / x, b / y);
    cout << t * x << " " << t * y << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}