// https://codeforces.com/contest/1152/problem/C
// Neko does Maths

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll lcm(ll a, ll b, ll g)
{
    return a * b / g;
}

void fix(ll a, ll b, ll i, ll &l, ll &k)
{
    ll tmp = ((a + i - 1) / i) * i - a;
    ll st = lcm(a + tmp, b + tmp, i);
    if (st < l)
    {
        l = st;
        k = tmp;
    }
    else if (st == l)
        k = min(k, tmp);
}

ll solve()
{
    ll a, b, k = 0;
    cin >> a >> b;
    if (a == b)
        return 0;
    if (a > b)
        swap(a, b);
    ll d = b - a, l = lcm(a, b, __gcd(a, b));
    for (ll i = 1; i * i <= d; i++)
    {
        if (d % i == 0)
        {
            fix(a, b, i, l, k);
            fix(a, b, d / i, l, k);
        }
    }
    return k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}