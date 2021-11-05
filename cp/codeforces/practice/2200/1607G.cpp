// https://codeforces.com/contest/1607/problem/G
// Banquet Preparations 1

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

void solve()
{
    int n;
    ll m, sum = 0, a_sum = 0, rem = 0;
    cin >> n >> m;
    vector<ll> a(n), b(n), useA(n), useB(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        useB[i] = min(m, b[i]);
        useA[i] = m - useB[i];
        a_sum += a[i] - useA[i];
        rem += min(a[i] - useA[i], useB[i]);
        sum += a[i] + b[i];
    }
    ll tot = sum - m * n;
    ll b_sum = tot - a_sum;
    ll ans = abs(b_sum - a_sum);
    if (b_sum < a_sum)
    {
        ll diff = a_sum - b_sum;
        rem = min(diff / 2, rem);
        a_sum -= rem;
        b_sum = tot - a_sum;
        ans = abs(a_sum - b_sum);
        for (int i = 0; rem > 0 && i < n; i++)
        {
            ll pos = min(rem, min(a[i] - useA[i], useB[i]));
            rem -= pos;
            useA[i] += pos;
            useB[i] -= pos;
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        cout << useA[i] << " " << useB[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}