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

const int N = 16, M = 50;
ll fac[N], pw2[M];
ll solve()
{
    ll n;
    cin >> n;
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    ll res = __builtin_popcountll(n);
    for (ll mask = 0; mask < (1 << N); mask++)
    {
        ll sum = 0;
        for (int bit = 0; bit < N; bit++)
            if ((mask >> bit) & 1)
                sum += fac[bit];
        if (sum <= n)
        {
            ll req = n - sum;
            ll bit0 = (req & 1), bit1 = ((req >> 1) & 1);
            if (((mask & bit0) == 0) && ((mask & bit1) == 0))
                res = min(res, 0ll + __builtin_popcountll(mask) + __builtin_popcountll(req));
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fac[0] = 1ll;
    for (int i = 1; i < N; i++)
        fac[i] = fac[i - 1] * (i + 1);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}