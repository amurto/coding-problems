// https://codeforces.com/contest/535/problem/C
// Tavas and Karafs

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e18;
ll calc(ll a, ll d, ll n, ll t)
{
    ll tn = a + (n - 1) * d;
    if (tn > t)
        return inf;
    return (n * (2 * a + (n - 1) * d)) / 2;
}

void solve()
{
    ll a, b, n, l, t, m;
    cin >> a >> b >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> t >> m;
        ll cur = a + (l - 1) * 1ll * b, tot = t * m;
        if (cur > t)
        {
            cout << "-1\n";
            continue;
        }
        ll low = l, high = l + (tot - cur + b - 1) / b, res = l;
        while (low < high)
        {
            ll mid = low + (high - low) / 2;
            ll sum = calc(cur, b, mid - l + 1, t);
            if (sum <= tot)
            {
                res = max(res, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if (calc(cur, b, low - l + 1, t) <= tot)
            res = max(res, low);
        cout << res << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}