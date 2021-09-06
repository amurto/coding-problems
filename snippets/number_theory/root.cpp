#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll sq_root(ll x)
{
    ll l = 0, r = 2e9 + 1;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    if (l * l == x)
        return l;
    return 0;
}

ll cube_root(ll x)
{
    ll l = 0, r = 1259922;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    if (l * l * l == x)
        return l;
    return 0;
}

ll quad_root(ll x)
{
    ll l = 0, r = 37607;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid * mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    if (l * l * l * l == x)
        return l;
    return 0;
}