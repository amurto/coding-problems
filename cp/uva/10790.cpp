// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1731
// How Many Points of Intersection?

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b, c = 1;
    while (cin >> a >> b && (a + b > 0))
    {
        ll t = 0, sum = 0, res = 0;
        for (ll i = 1; i < b; i++)
            sum += i;
        for (ll i = 0; i < a; i++)
            res += sum * i;
        cout << "Case " << c++ << ": " << res << "\n";
    }
    return 0;
}