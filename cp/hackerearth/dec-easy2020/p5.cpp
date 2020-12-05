#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool fac(ll b, ll v1, bool neg)
{
    ll v2 = b / v1;
    v1 *= b;
    v2 *= b;
    if (v1 < v2)
        swap(v1, v2);
    ll p1 = v2 + (v1 - v2) / 2;
    ll p2 = v1 - p1;
    if (p1 >= 0 && p2 >= 0 && max(p1, p2) - min(p1, p2) == v2)
    {
        if (neg)
            cout << max(p1, p2) << " " << min(p1, p2) << "\n";
        else
            cout << min(p1, p2) << " " << max(p1, p2) << "\n";
        return true;
    }
    return false;
}

void solve()
{
    ll b;
    cin >> b;
    if (b == 0)
    {
        cout << 1 << " " << 1 << "\n";
        return;
    }
    bool neg = false;
    if (b < 0)
    {
        neg = true;
        b = abs(b);
    }
    for (ll i = 1; i * i <= b; i++)
    {
        if (b % i == 0 && fac(b, i, neg))
            return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}