// https://codeforces.com/contest/1395/problem/D
// Boboniu Chats with Du

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n, d, m, rem, spc;
    cin >> n >> d >> m;
    ll x;
    vector<ll> a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        (x <= m) ? a.pb(x) : b.pb(x);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int sz1 = a.size(), sz2 = b.size();
    if (sz2 == 0)
    {
        ll sum = accumulate(a.begin(), a.end(), 0ll);
        return sum;
    }
    for (int i = 1; i < sz1; i++)
        a[i] += a[i - 1];
    for (int i = 1; i < sz2; i++)
        b[i] += b[i - 1];
    ll res = b[min(sz2, (n + d) / (d + 1)) - 1];
    for (int i = 0; i < sz1; i++)
    {
        rem = n - i - 1;
        spc = min(sz2, (rem + d) / (d + 1));
        res = max(res, a[i + max(0, rem - spc * (d + 1))] + b[spc - 1]);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}