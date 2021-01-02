// https://codeforces.com/contest/834/problem/C
// The Meaningless Game

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll cube_root(ll x)
{
    ll l = 0, r = 1e6 + 1;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    return l;
}

bool solve()
{
    ll a, b;
    cin >> a >> b;
    ll c = cube_root(a*b);
    return (c * c * c == a * b && a % c == 0 && b % c == 0);
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