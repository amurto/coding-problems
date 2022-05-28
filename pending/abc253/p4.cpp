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

ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

ll nc2(ll n)
{
    return (n * (n + 1)) / 2;
}

ll cnt(ll n, ll x)
{
    return x * nc2(n / x);
}

ll solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    return nc2(n) - cnt(n, a) - cnt(n, b) + cnt(n, lcm(a, b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}