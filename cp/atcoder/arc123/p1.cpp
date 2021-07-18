#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve(ll a, ll b, ll c)
{
    ll res = 0;
    if (b < a)
    {
        res += abs(a - b);
        b = a;
    }
    if (c < b)
    {
        res += abs(b - c);
        c = b;
    }
    ll d = c - a;
    if (d % 2 == 1)
    {
        res++;
        c++;
        d++;
    }
    ll x1 = b - a, x2 = c - b;
    if (x1 > x2)
        res += x1 - x2;
    else
        res += (d / 2) - x1;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    ll res = solve(a, b, c);
    swap(a, c);
    res = min(res, solve(a, b, c));
    cout << res << "\n";
    return 0;
}