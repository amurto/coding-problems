#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

void solve()
{
    int k;
    ll n, m, q, x, y, t;
    cin >> n >> m >> k;
    vector<pii> p(k);
    for (int i = 0; i < k; i++)
    {
        cin >> p[i].second >> x >> y;
        p[i].first = n - x + m - y;
    }
    sort(p.begin(), p.end());
    vector<ll> d(k), mx(k);
    for (int i = 0; i < k; i++)
        d[i] = p[i].first;
    mx[0] = p[0].second;
    for (int i = 1; i < k; i++)
        mx[i] = max(mx[i - 1], p[i].second);
    cin >> q;
    while (q-- > 0)
    {
        cin >> t;
        int idx = upper_bound(d.begin(), d.end(), t) - d.begin();
        idx--;
        (idx < 0) ? cout << 0 : cout << (idx + 1) * mx[idx];
        cout << "\n";
    }
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