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

const ll MX = 1e18;
ll query(ll x)
{
    cout << "? " << x << endl;
    ll ans = 0;
    cin >> ans;
    return ans;
}

void solve()
{
    ll a = query(MX);
    a = MX - a;
    ll b = query(a * 2 - 1)+1;
    cout << "! " << b << endl;
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