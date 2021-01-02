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