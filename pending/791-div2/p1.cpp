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
    ll n;
    cin >> n;
    if ((n & 1) || n < 4)
    {
        cout << "-1\n";
        return;
    }
    ll mn = n / 6, rem_mn = n % 6;
    if (rem_mn > 0)
        mn++;
    ll mx = n / 4;
    cout << mn << " " << mx << "\n";
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