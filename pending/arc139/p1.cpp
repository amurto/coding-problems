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

ll ctz(ll v)
{
    ll cnt = 0;
    while (v % 2 == 0)
    {
        cnt++;
        v /= 2;
    }
    return cnt;
}

ll solve()
{
    int n;
    cin >> n;
    vector<ll> T(n), arr(n);
    for (int i = 0; i < n; i++)
        cin >> T[i];
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        ll v = 1ll << T[i];
        arr[i] = max(v, ((mx + v - 1) / v) * v);
        if (ctz(arr[i]) > T[i])
            arr[i] += v;
        mx = arr[i] + 1;
    }
    return arr[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}