// https://codeforces.com/contest/424/problem/C
// Magic Formulas

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, v, Q = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v;
        Q ^= v;
    }
    vector<ll> f(n + 1);
    for (ll i = 1; i <= n; i++)
        f[i] = f[i - 1] ^ i;
    for (ll k = 1; k <= n; k++)
    {
        if (n / k & 1)
            Q ^= f[k - 1];
        Q ^= f[n % k];
    }
    cout << Q << "\n";
    return 0;
}