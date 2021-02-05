// https://codeforces.com/contest/592/problem/C
// The Big Race

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool check(ll t, ll w, ll b, ll g)
{
    w /= g;
    if (w > t || b > t)
        return true;
    return (b > t / w);
}
void solve()
{
    ll t, w, b, num = 0;
    cin >> t >> w >> b;
    ll g = __gcd(w, b);
    if (w > b)
        swap(w, b);
    if (check(t, w, b, g))
        num = min(t, w - 1);
    else
    {
        ll lcm = (w / g) * b;
        ll q = t / lcm, r = t % lcm;
        num = q + q * (w - 1) + min(w - 1, r);
    }
    g = __gcd(num, t);
    num /= g;
    t /= g;
    cout << num << "/" << t << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}