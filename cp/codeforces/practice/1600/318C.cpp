// https://codeforces.com/contest/318/problem/C
// Perfect Pair

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll op(ll x, ll y, ll m)
{
    if (m <= 0 && x < m && y < m)
        return -1;
    if (x <= 0 && y <= 0 && m > 0)
        return -1;
    ll c = 0;
    if (x < y)
        swap(x, y);
    while (x < m)
    {
        ll d = (x - y + x - 1) / x;
        y += d * x;
        if (y <= x)
        {
            d++;
            y += x;
        }
        c += d;
        swap(x, y);
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x, y, m, c = 0;
    cin >> x >> y >> m;
    cout << op(x, y, m) << "\n";
    return 0;
}