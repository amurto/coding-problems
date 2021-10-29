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

ll solve()
{
    ll n, k, p = 0, res = 0;
    cin >> n >> k;
    if (n == 1 && k == 1)
        return 0;
    n--;
    for (ll i = 0; n > 0 && i <= 60; i++)
    {
        if ((1ll << i) <= k)
        {
            p = i;
            n -= (1ll<<i);
            res++;
        }
    }
    if (n > 0)
        res += (n + k - 1) / k;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}