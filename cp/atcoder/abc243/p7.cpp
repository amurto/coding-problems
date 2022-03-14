#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MX1 = 9e18, MX2 = 3e9, MX3 = 4e5 + 5;
ll dp[MX3], pdp[MX3];

ll sq_root(ll x)
{
    ll l = 0, r = 3e9 + 5;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    return l;
}

void init()
{
    dp[1] = pdp[1] = 1;
    for (ll i = 2; i < MX3; i++)
    {
        dp[i] = 0;
        ll v = sq_root(i);
        dp[i] = pdp[v];
        pdp[i] = pdp[i - 1] + dp[i];
    }
}

ll solve()
{
    ll x, res = 0;
    cin >> x;
    ll sq = sq_root(x);
    for (ll i = 1; i * i <= sq; i++)
        res += dp[i] * (sq - i * i + 1);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}