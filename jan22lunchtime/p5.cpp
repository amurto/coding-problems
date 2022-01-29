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
    ll n, m, k, res = 0;
    cin >> n >> m >> k;
    ll X = 0;
    vector<ll> arr(n);
    vector<bool> flip(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll msb = -1;
    for (ll bit = m - 1; msb == -1 && bit >= 0; bit--)
    {
        ll cnt = 0;
        for (ll x : arr)
            if ((x >> bit) & 1ll)
                cnt++;
        if (n - cnt > cnt)
        {
            msb = bit;
            for (ll i = 0; i < n; i++)
                if (!((arr[i] >> bit) & 1ll))
                    flip[i] = true;
        }
    }
    if (msb >= 0)
    {
        X |= (1ll << msb);
        ll sz = 0;
        for (int i = 0; i < n; i++)
            if (flip[i])
                sz++;
        for (ll bit = msb - 1; bit >= 0; bit--)
        {
            ll cnt = 0;
            for (ll i = 0; i < n; i++)
                if (flip[i])
                    if ((arr[i] >> bit) & 1ll)
                        cnt++;
            if (sz - cnt > cnt)
                X |= (1ll << bit);
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (flip[i])
            arr[i] ^= X;
        res += arr[i];
    }
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