#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll sq_root(ll x)
{
    ll l = 0, r = 2e9 + 1;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    return l + 1;
}

bool prime(ll x)
{
    if (x == 2)
        return true;
    if (x == 1 || x % 2 == 0)
        return false;
    for (ll i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}

ll solve()
{
    ll z;
    cin >> z;
    ll res = 0, sq = sq_root(z);
    vector<ll> seq;
    for (ll i = max(1ll, sq - 600); i <= sq + 600; i++)
        if (prime(i))
            seq.pb(i);
    for (int i = 1; i < seq.size(); i++)
        if (seq[i - 1] * seq[i] <= z)
            res = max(res, seq[i - 1] * seq[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}