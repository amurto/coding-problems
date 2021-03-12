// https://codeforces.com/problemset/problem/1334/D
// Minimum Euler Cycle

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void ls(ll &x, ll &y, ll tp, ll n)
{
    ll add = n - 1, cur = 0, last = 0;
    while (cur <= tp)
    {
        last = cur;
        cur += add;
        add--;
        x++;
    }
    y = tp - last + 1 + x;
}

void solve()
{
    ll n, l, r;
    cin >> n >> l >> r;
    ll lb = l, ub = r, last = n * (n - 1) + 1;
    if (l == r && r == last)
    {
        cout << "1\n";
        return;
    }
    if (lb & 1)
        lb--;
    else
        lb -= 2;    
    if (ub == last)
        ub--;
    else if (ub & 1)
        ub++;
    ll x = 0, y = 0;
    ls(x, y, lb / 2, n);
    vector<ll> seq;
    for (ll z = lb; z < ub; z += 2)
    {
        seq.pb(x);
        seq.pb(y);
        y++;
        if (y > n)
        {
            x++;
            y = x + 1;
        }
    }
    if (r == last)
        seq.pb(1);
    for (ll i = 0, cur = lb + 1; i < seq.size(); i++, cur++)
        if (cur >= l && cur <= r)
            cout << seq[i] << " ";
    cout << "\n";
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