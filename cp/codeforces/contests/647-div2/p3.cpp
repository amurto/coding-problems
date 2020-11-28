#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int cnt(ll x)
{
    int c = 0;
    while (x > 0)
    {
        c += (x & 1);
        x = x >> 1;
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll n, ans = 0;
        cin >> n;
        for (ll i = 1; i <= n; i <<= 1)
            if (n & i)
                ans += i * 2 - 1;
        cout << ans << "\n";
    }
    return 0;
}