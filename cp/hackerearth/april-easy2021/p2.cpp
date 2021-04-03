#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MOD = 1e9 + 7;

ll add(ll x, ll y)
{
    x %= MOD;
    y %= MOD;
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

ll mul(ll x, ll y)
{
    x %= MOD;
    y %= MOD;
    return (x * y) % MOD;
}

int solve()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<ll> a(n), b(n), sufA(n + 1), sufB(n + 1), prod(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = n - 1; i >= 0; i--)
    {
        sufA[i] = add(sufA[i + 1], mul(a[i], a[i]));
        sufB[i] = add(sufB[i + 1], mul(b[i], b[i]));
        prod[i] = add(prod[i + 1], mul(a[i], b[i]));
        res = add(res, mul(mul(a[i], a[i]), sufB[i + 1]));
        res = add(res, mul(mul(b[i], b[i]), sufA[i + 1]));
        res = add(res, -mul(2, mul(mul(a[i], b[i]), prod[i + 1])));
    }
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