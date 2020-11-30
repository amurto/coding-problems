// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1243
// 10302 - Summation of Polynomials

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x;
    while (cin >> x)
    {
        ll ans = x * (x + 1) / 2;
        ans *= ans;
        cout << ans << "\n";
    }
    return 0;
}