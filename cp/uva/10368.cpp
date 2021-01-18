// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1309
// 10368 - Euclid's Game

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll play(ll x, ll y, ll cur)
{
    if (x < y)
        swap(x, y);
    if (x % y == 0)
        return cur;
    if (play(y, x % y, cur ^ 1) == cur || (x / y > 1 && play(y + x % y, y, cur ^ 1) == cur))
        return cur;
    return cur ^ 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x, y;
    while (cin >> x >> y && (x + y > 0))
        play(x, y, 0) == 0 ? cout << "Stan wins\n" : cout << "Ollie wins\n";
    return 0;
}