#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

void solve()
{
    int n, q;
    cin >> n;
    vector<ll> a(n), t(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> t[i];
    cin >> q;
    vector<ll> x(q);
    for (int i = 0; i < q; i++)
        cin >> x[i];
    ll add = 0, l = -1e18, r = 1e18;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == 1)
        {
            add += a[i];
            l += a[i];
            r += a[i];
        }
        else if (t[i] == 2)
        {
            l = max(l, a[i]);
            r = max(r, a[i]);
        }
        else
        {
            l = min(l, a[i]);
            r = min(r, a[i]);
        }
    }
    for (int i = 0; i < q; i++)
        cout << min(r, max(l, x[i] + add)) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}