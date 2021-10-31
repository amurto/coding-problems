// https://codeforces.com/contest/1461/problem/E
// Water Level

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

bool solve()
{
    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    vector<ll> nxt(x);
    for (ll i = 0; i < x; i++)
        nxt[i] = (i + y) % x;
    if (x > y)
    {
        if (k + y <= r)
            k += y;
        k -= x;
        if (k < l)
            return false;
        t--;
        // we lose x-y everyday
        return ((k - l) / (x - y)) >= t;
    }
    // x <= y
    ll rem = r - y;
    if (rem < l)
        return (k - l) / x >= t;
    rem -= l;
    if (rem >= x)
        return true;
    t -= ((k - l) / x);
    vector<bool> vis(x);
    for (ll cur = (k - l) % x; t > 0; cur = nxt[cur])
    {
        if (cur > rem)
            return false;
        if (vis[cur])
            return true;
        vis[cur] = true;
        t -= ((cur + y) / x);
    }
    return t <= 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}