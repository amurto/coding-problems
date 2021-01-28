// https://codeforces.com/contest/476/problem/C
// Dreamoon and Sums

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b, res = 0;
    cin >> a >> b;
    for (ll m = 1; m < b; m++)
    {
        ll l = b * m + m;
        res = res + ((a * (2 * l + (a - 1) * (m * b))) / 2) % MOD;
        res %= MOD;
    }
    cout << res << "\n";
    return 0;
}