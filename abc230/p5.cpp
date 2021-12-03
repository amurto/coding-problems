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

ll solve()
{
    ll n, res = 0;
    cin >> n;
    vector<ll> divs1, divs2;
    for (ll i = 1; i * i <= n; i++)
    {
        divs1.pb(i);
        divs2.pb(n / i);
    }
    divs2.pb(divs1.back());
    int sz = (int)divs1.size();
    for (int i = 0; i < sz; i++)
        res += (divs2[i] - divs2[i + 1]) * divs1[i];
    for (ll i = 1; i * i <= n; i++)
        res += n / i;
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