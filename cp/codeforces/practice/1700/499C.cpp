// https://codeforces.com/contest/499/problem/C
// Crazy Town

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int check(ll p)
{
    if (p > 0)
        return 1;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x1, y1, x2, y2, n, a, b, c, res = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if (check(a * x1 + b * y1 + c) != check(a * x2 + b * y2 + c))
            res++;
    }
    cout << res << "\n";
    return 0;
}